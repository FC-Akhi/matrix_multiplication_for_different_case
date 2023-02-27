// cpu_matrix_mult_v2
// User-input matrix
// Transpose 2nd matrix for performance improve
// Allocating memory in heap

#include <iostream>

// transpose unit
void mat_transpose(float *mat_b, float *mat_b_transpose, int row_b, int col_b)
{
    int k = 0;

    for(int j = 0; j < col_b; j++){
        for(int i = 0; i < row_b; i++){
            mat_b_transpose[k] = mat_b[(i * col_b) + j];
            k++;
        }
    }

}



// mat_a(row_a x col_a)  x  mat_b_transpose(col_b x row_b)  =  mat_res_3(row_a x col_b)
void cpu_matrix_mult_v2(float *mat_a, float *mat_b, float *mat_b_transpose, float *mat_res, int row_a, int col_a, int row_b, int col_b)
{   
    
    // transpose 2nd matrix for better performance
    mat_transpose(mat_b, mat_b_transpose, row_b, col_b);

    for (int i = 0; i < row_a; ++i) 
    {
        for (int k = 0; k < col_b; ++k) 
        {
            float tmp = 0.0f;
            for (int j = 0; j < col_a; ++j)
            {
                tmp += mat_a[(i * col_a) + j] * mat_b_transpose[(k * col_a) + j];
            }
            mat_res[(i * col_b) + k] = tmp;
            // m++;
        }
    }
}





int main()
{

    int row_a;
    int col_a;
    int row_b;
    int col_b;

    // mat_a row and col size input
    std::cout << "Enter number of row in array 1::";
    std::cin >> row_a;
    std::cout << "Enter number of col in array 1::";
    std::cin >> col_a;

    std::cout << "Enter number of row in array 2::";
    std::cin >> row_b;
    std::cout << "Enter number of col in array 2::";
    std::cin >> col_b;


    // matrix declaration
    float *mat_a = new float[row_a * col_a];
    float *mat_b = new float[row_b * col_b];
    float *mat_b_transpose = new float[row_b * col_b];

    float *mat_res = new float[row_a * col_b];
   
    
    
    // take input mat_a
    for(int i = 0; i < row_a * col_a; i++)
        std::cin >> mat_a[i];
    
    // take input mat_b
    for(int i = 0; i < row_b * col_b; i++)
        std::cin >> mat_b[i];
    

    // matrix multiplication unit
    cpu_matrix_mult_v2(mat_a, mat_b, mat_b_transpose, mat_res, row_a, col_a, col_b, row_b);


    std::cout << "\n";

    for(int i = 0; i < row_a * col_b; i++){
        std::cout << mat_res[i] << " ";
        
    }
    
    delete mat_a;
    delete mat_b;
    delete mat_b_transpose;
    
    delete mat_res;
    
    return 0;
}



