// cpu_matrix_mult_v1
// static matrix

#include<iostream>
#include<vector>

// mat_a(row_a x col_a)  x  mat_b(row_b x col_b)  =  mat_res_3(row_a x col_b)
void cpu_matrix_mult_v1(std::vector<int> &mat_a_vec, std::vector<int> &mat_b_vec, std::vector<int> &mat_res_1_vec, int row_a, int col_a, int col_b)
{
    for (int i = 0; i < row_a; ++i) 
    {
        for (int j = 0; j < col_b; ++j) 
        {
            int tmp = 0;
            for (int k = 0; k < col_a; ++k)
            {
                tmp += mat_a_vec[(i * col_a) + k] * mat_b_vec[(k * col_b) + j];
            }
            mat_res_1_vec[(i * col_b) +j] = tmp;
        }
    }
}



int main()
{   
    int row_a;
    int col_a;
    int row_b;
    int col_b;

    



    // =====Matries Dimensions input from user======
    // 1st matrix row and col size input
    std::cout<<"Enter number of row in array 1::";
    std::cin>>row_a;
    std::cout<<"Enter number of col in array 1::";
    std::cin>>col_a;

    // 2nd matrix row and col size input
    std::cout<<"Enter number of row in array 2::";
    std::cin>>row_b;
    std::cout<<"Enter number of col in array 2::";
    std::cin>>col_b;




    // =====Matries Dimensions======================
    // dimension of matrix a b and res
    int mat_a_dim = row_a * row_b;
    int mat_b_dim = row_b *col_b;
    int mat_res_dim = row_a * col_b;



    
    // =====Matries Declaration======================
    // matrix declaration as vector
    std::vector<int> mat_a_vec(mat_a_dim, 0);
    std::vector<int> mat_b_vec(mat_b_dim, 0);
    

    // result matrix declaration as vector
    std::vector<int> mat_res_1_vec(mat_res_dim);
    
    // =====Taking inputs for mat_a_vec and matr_b_vec======
    // take input for mat_a_vec
    for(int i = 0; i < mat_a_dim; i++)
        mat_a_vec.data()[i] = (rand() % 100) + 0;  //Generate number between 0 to 2
    std::cout << "RAND_MAX: " << RAND_MAX << std::endl;
    for(int i = 0; i < mat_a_dim; i++)
        std::cout << "Matrix 1: " << mat_a_vec.data()[i] << " ";
    std::cout<<"\n";

    // generating int values for mat_b_vec 0 to 2
    for(int i = 0; i < mat_b_dim; i++)
        mat_b_vec.data()[i] = (rand() % 100) + 0; ;  //Generate number between 0 to 2

    for(int i = 0; i < mat_b_dim; i++)
        std::cout << "Matrix 2: " << mat_b_vec.data()[i] << " ";
    std::cout<<"\n";
   
    cpu_matrix_mult_v1(mat_a_vec, mat_b_vec, mat_res_1_vec, row_a, col_a, col_b);

    for(int i = 0; i < row_a * col_b; i++){
        std::cout << mat_res_1_vec[i] << " ";
    }


    return 0;
}