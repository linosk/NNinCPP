#include "mnist_reader.h"

//Think this through
MNIST_READER::MNIST_READER(MNIST_READER_TYPE Type) :  
Label(1),
Matrix(1,1),
Height(28), 
Width(28){

    Set_type(Type);

}

void MNIST_READER::Set_type(MNIST_READER_TYPE Type){
    
    switch(Type){
        case 0:{

            Data_set_type = Type;
            Number_of_images = Training_size;
            Pixels_per_image = Image_surface;
            Label.resize(Number_of_images,0);
            Matrix.Resize(Number_of_images,Pixels_per_image);
            if(Matrix.Read_from_file(Training_data_location)){
                throw std::invalid_argument("Value not read correctly.");
            }

            break;
        }
        case 1:{

            Data_set_type = Type;
            //Number_of_images = Test_size;
            //Label.resize(Test_size,0);
            //Matrix.Resize(Test_size,Number_of_images);

            break;
        }
        default:{
            		
            throw std::invalid_argument("Choose other dataset type.");

            break;
        }
    }

}