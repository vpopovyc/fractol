
__kernel void       computing_set(__global int *A, __constant double *meta_data)
{
    double MinRe = meta_data[1];
    double MaxRe = meta_data[2];
    double MinIm = meta_data[3];
    double MaxIm = meta_data[4];
    double Re_factor = meta_data[5];
    double Im_factor = meta_data[6];
    unsigned MaxIterations = meta_data[0];

    // Window dimensions
    uint x = get_global_id(0) % 1280;
    uint y = get_global_id(0) / 768;

    double2  vec_c;
    vec_c.y = MaxIm - y * Im_factor;
    vec_c.x = MinRe + x * Re_factor;
    
    double2  vec_Z = vec_c;
    char     is_inside = 0;
    double2  vec_Z_2;

    for (uint iter = 0; iter < MaxIterations; ++iter)
    {
        vec_Z_2 = vec_Z * vec_Z;
        if ((vec_Z_2.x + vec_Z_2.y) > 4)
        {
            is_inside = 1;
            break ;
        }
        vec_Z.y = 2 * vec_Z.x * vec_Z.y + vec_c.y;
        vec_Z.x = vec_Z_2.x - vec_Z_2.y + vec_c.x;
    }
    if (is_inside == 0) {

        A [get_global_id(0)] = 0x820202;
    }
    else {

        A [get_global_id(0)] = 0xffffff;
    }
}
