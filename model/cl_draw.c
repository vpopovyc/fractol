/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_draw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <vpopovyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 15:55:07 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/07/06 22:16:47 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"
#include "../headers/cl_data.h"

#define EXIT_FAILURE 1



/*
** JIT compiling
** Get kernels file bytes, create kernel object file, then
** compile binary using that object
*/

void    cl_compile_kernel(t_cl *cl, const char *filepath)
{
    int err;
    FILE    *kernel_file;
    size_t  kernel_size;
    char    *kernel = malloc(sizeof(char) * BUFF);

    // Load kernel from file
    kernel_file = fopen(filepath, "r");
    kernel_size = fread(kernel, 1, BUFF, kernel_file);
    kernel[kernel_size] = '\0';
    fclose(kernel_file);
    // Create obj
    cl->program = clCreateProgramWithSource(cl->context, 1, (const char **) & kernel, NULL, &err);
    if (!cl->program || err != CL_SUCCESS)
    {
        printf("Error: Failed to create compute program!\n");
        return ;
    }
    free(kernel);
    // Compile
    err = clBuildProgram(cl->program, 1, &(cl->device), NULL, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        size_t len;
        char buffer[2048];

        printf("Error: Failed to build program executable!\n");
        clGetProgramBuildInfo(cl->program, cl->device, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
        printf("%s\n", buffer);
        exit(1);
    }
    // Link
    cl->kernel = clCreateKernel(cl->program, "computing_set", &err);
    if (!cl->kernel || err != CL_SUCCESS)
    {
        printf("Error: Failed to create compute kernel!\n");
        exit(1);
    }
}

/*
** Create buffers and fill them with needed data
** Create OpenCL memory objects
** Enqueue synchronous writes of data, that was created, to that memory objects
*/

void    cl_create_args(t_cl *cl, t_const *var)
{
    cl_double   *mem2;
    int err;

    mem2 = cl->constant;
    // Load const values to memory object
    load_to_arg(var, mem2);

    err = clEnqueueWriteBuffer(cl->queue, cl->constants, CL_TRUE, 0, CONST * sizeof(cl_double), mem2, 0, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to write to source array!\n");
        exit(1);
    }
    // Enqueue arg to kernel
    err = 0;
    err = clSetKernelArg(cl->kernel, 0, sizeof(cl_mem), &cl->input);
    err |= clSetKernelArg(cl->kernel, 1, sizeof(cl_mem), &cl->constants);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to set kernel arguments! %d\n", err);
        exit(1);
    }
}

/*
** Enqueue execution command of previously created kernel, then
** Enqueue read command from memory object to result buffer
*/

void    cl_execute_kernel(t_cl *cl, t_mlx *mlx)
{
    size_t  global_work_size = SIZE;
    int     err;


    // Execute kernel
    err = clEnqueueNDRangeKernel(cl->queue, cl->kernel, 1, NULL, &global_work_size, NULL, 0, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to execute kernel!\n");
        return ;
    }
    // Get data back
    clFinish(cl->queue);

    err = clEnqueueReadBuffer(cl->queue, cl->input, CL_TRUE, 0, SIZE * sizeof(int32_t), cl->image, 0, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to read output array! %d\n", err);
        exit(1);
    }

    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
}

void    cl_update_model(t_mlx *mlx)
{
    static char fractal;

    if (fractal != mlx->current_fractal)
    {
        // Compile kernel
        cl_compile_kernel(mlx->cl, mlx->fractal_path);
        fractal = mlx->current_fractal;
    }
    // Args
    cl_create_args(mlx->cl, mlx->var);
    // Runtime
    cl_execute_kernel(mlx->cl, mlx);

    // clReleaseMemObject(mlx->cl->input);
    // clReleaseMemObject(mlx->cl->constants);
    // clReleaseProgram(mlx->cl->program);
    // clReleaseKernel(mlx->cl->kernel);
    // clReleaseCommandQueue(mlx->cl->queue);
    // clReleaseContext(mlx->cl->context);
}
