#include <iostream>
#include <fstream>

void array_to_file(int* arr,
    size_t size,
    const char* file_name)
{
    //std::fstream out(file_name, std::ios::out | std::ios::app);
    std::fstream out(file_name, std::ios::out);
    for (size_t idx = 0; idx < size; ++idx)
        out << arr[idx] << ' ';
    out << '\n';
    out.close();
}

void array_to_bin_file(int* arr,
    size_t size,
    const char* file_name)
{
    std::fstream out(file_name,
        (std::ios::out | std::ios::binary));
    out.write((char*)arr, size * sizeof(int));
    out.close();
}

int* array_from_bin_file(size_t& size,
    const char* file_name)
{
    std::fstream in(file_name,
        (std::ios::in | std::ios::binary));
    // go to the end of file
    in.seekg(0, std::ios::end);
    // get position of file
    size_t byte_size = (int)in.tellg() + 1;
    // convert to int size
    size = byte_size / sizeof(int);
    // back to file start
    in.seekg(0, std::ios::beg);
    in.clear();

    int* arr = new int[size];
    in.read((char*)arr, byte_size);
    in.close();
    return arr;
}

int main()
{
    int arr[] = { 2, 3, 2'000'000'000, 2'000'000'001, 2'000'000'002 };
    size_t size = sizeof(arr) / sizeof(int);
    array_to_file(arr, size, "out.txt");
    array_to_bin_file(arr, size, "out.dat");
    int* read_arr = array_from_bin_file(size, "out.dat");
    for (size_t idx = 0; idx < size; ++idx)
        std::cout << read_arr[idx] << '\n';
    return 0;
}
