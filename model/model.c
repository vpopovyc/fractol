/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <vpopovyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 15:19:20 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/07/11 18:16:56 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cl_data.h"

/*
** Determine GPU device, create context object with it and create command 
** queue with selected context to specific device
*/

static void     cl_host_part(t_cl *cl)
{
    int err;  
    // Get platform and device to use
    err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &(cl->device), NULL);
    if (err != CL_SUCCESS)
    {
        write(1, "error code 1\n", 13);
        return ;
    }
    // Create context
    cl->context = clCreateContext(0, 1, &cl->device, NULL, NULL, &err);
    if (!cl->context || err != CL_SUCCESS)
    {
        write(1, "error code 2\n", 13);
        return ;
    }
    // Create command queue
    cl->queue = clCreateCommandQueue(cl->context, cl->device, 0, &err);
    if (!cl->queue || err != CL_SUCCESS)
    {
        write(1, "error code 3\n", 13);
        return ;
    }
}

/*
** JIT compiling
** Get kernels file bytes, create kernel object file, then
** compile binary using that object
*/

static void     allocate_memory_objects(t_cl *cl)
{
    int     err;

    err = 0;
    cl->constant = (cl_double *)malloc(sizeof(cl_double) * CONST);
    cl->input = clCreateBuffer(cl->context, CL_MEM_READ_WRITE, SIZE * sizeof(int32_t), NULL, &err);
    if (err != CL_SUCCESS)
    {
        write(1, "error code 4\n", 13);
        return ;
    }
    cl->constants = clCreateBuffer(cl->context, CL_MEM_READ_ONLY, CONST * sizeof(cl_double), NULL, &err);
    if (!cl->input || !cl->constants || err != CL_SUCCESS)
    {
        write(1, "error code 5\n", 13);
        exit(1);
    } 
}

void            init_model(t_cl *cl)
{
    // Host part
    cl_host_part(cl);
    //
    allocate_memory_objects(cl);
}