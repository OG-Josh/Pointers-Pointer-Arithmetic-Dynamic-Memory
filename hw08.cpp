/* ======================================================================================= */
/* ======================================================================================= */
// Class: CS-1C
// Creator: Joshua Yang
// Contact: joshuayang0324@gmail.com
// Professor: Kath
// Date: 3/5/2019
/* ======================================================================================= */
// hw08.cpp
// to illustrate pointers, pointer arithmetic & dynamic memory
/* ======================================================================================= */
// Work: 
// CS1C Spring 2019 TTH HW-1 50pts Due: Th 1/24/2019
// cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ script hw01.scr
// Script started, file is hw01.scr
// cs1c@cs1c-VirtualBox ~/cs1c/hw01 $ date
// ... 
// Cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ Is -1
// ... 
// Cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ make all
// ...
// Cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ Is -1
// ...
// Cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ ./hw01
// ...//print out parts a, d & g above
// cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ exit
// Script done, file is hw01.scr
// Cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ make tar
// ...
// Submit the tar package file hw01.tar by Thursday January 24, 2019.
/* ======================================================================================= */
/* ======================================================================================= */
// Code:
#include <iostream>

using namespace std;

// function definitions go into hw08.cpp:

// hw08.cpp

namespace hw08
{

    const int ARRAY_SIZE = 5;
    const int DYNAMIC_SIZE = 15;
    const int TIC_TAC_TOE_SIZE = 3;

// function definitions:

//------------------------------------------------------------------------------

    int increment_value(int x)
    // pass a value, compute a new value by adding 5 to x and return it
    {
        // ...
        x = x + 5;          // temp, replace when defining function
        return x; // included so that incomplete lab code will compile
    }

    void increment_pointer(int* p)
    // pass a pointer, increment value of p by 1
    {
        *p = *p + 1;
    }

    void increment_reference(int& r)
    // pass a reference, increment value of r by 1
    {
        r = r + 1;
    }

//------------------------------------------------------------------------------

    void print_2darray_subscript(double twoDD[][ARRAY_SIZE], int row, int col)
    // print array using subscripts
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                cout << twoDD[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }

    void print_2darray_pointer(double* twoDD, int row, int col)
    // print array using pointer arithmetic
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // our 2d array is layed out linearly in memory as contiguous rows, one after another, there are #row rows
                // each row has #col columns

                // to compute the offset using pointer math
                // offset from twoDD: #row (i) * #col + #col (j), result: pointer to array element
                cout << *(twoDD + (i * col + j)) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

//------------------------------------------------------------------------------

    void print_2darray_dynamic_subscript(int** twoDD, int row, int col)
    // print array using subscripts
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                cout << twoDD[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }

    void print_2darray_dynamic_pointer(int** twoDD, int row, int col)
    // print array using pointer arithmetic
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // our dynamic 2d array is an array of int pointers
                // each component in the array itself points to an array of ints
                // dynamic array rows are not contiguous in memory

                // to compute the offset using pointer math
                // offset from twoDD: move to the correct row, add #row (i), dereference to obtain pointer to row
                //                    next, add #col (j), result: pointer to array element
                cout << (*(*(twoDD + i) + j)) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

//------------------------------------------------------------------------------

    double* dynamic_allocation_array_doubles(int array_size)
    // the caller is responsible for the memory allocated
    {
        int* pi_array = new int[DYNAMIC_SIZE];
        // function uses pi_array
        // function responsible for cleaning up (i.e. deleting) memory allocated for pi_array
        // do stuff here with pi_array
        double* pd_array = new double[array_size];
        delete pi_array;    // dynamic memory allocated for pi_array not needed any longer, free it
        return pd_array;
    }

//------------------------------------------------------------------------------

}// hw08

//------------------------------------------------------------------------------

int main()
{
    // console header
    cout << endl;
    cout << "************************************** " << endl;
    cout << "*           Running HW08             * " << endl;
    cout << "*      Programmed by First Last      * " << endl;
    cout << "*      CS1C Date & Time              * " << endl;
    cout << "************************************** " << endl;
    cout << endl;

    // complete the following pointer examples
    // indicate if the requested operation is not allowed, why not?
    // Q#1 - pointer examples
    int x = 10;
    int *p = &x; // [1.1] variable p of type pointer to int points to x (i.e. int* p = ?;), use & to get the address of x
    //INVALID: x have type is int not double // [1.2] variable q of type pointer to double is points to x
    *p = 5; // [1.3] update the value of p to 5, use * to assign to x through p
    int x2 = *p; // [1.4] store the value of p in variable x2 of type int, use * to read x through p
    int *p2 = &x2; // [1.5] variable p2 of type pointer to int points to x2, use & to get a pointer to x2
    p = p2; // [1.6] assign p to p2, p2 and p both point to x
    *p = x2; // [1.7] point p to x2, what does p2 point to now?

    // complete the following reference examples
    // indicate if the requested operation is not allowed, why not?
    // Q#1 - reference examples
    int y = 50;
    int &r = x; // [1.8] variable r of type reference to int refers to x (i.e. int& p = ?;), nothing special to do here in the initializer
    //INVALID: reference double can not refer to int type // [1.9] variable s of type reference to double is refers to x
    r = 10; // [1.10] update the value of r to 10, assign to y through r (notice * is not needed)
    int y2 = r; // [1.11] store the value of r in variable y2 of type int, read y through r (notice * is not needed)
    int &r2 = y2; // [1.12] variable r2 of type reference to int refers to y2, get a reference to int y2
    r = r2; // [1.13] assign r to r2, the value of y is assigned to y2
    y2 = r; // [1.14] assign y2 to r, r2 and r both point to y2
    // INVALID. r2 need to initialized // [1.15] variable r3 of type reference to int is defined but not initialized (i.e. does not refer to an int)

    // Q#1 - pointer vs reference: increment functions
    // implementation the function definitions for the following increment operations
    { // allows definition of variables within block scope avoiding redefinition errors
        int x = 100;
        int x2 = 25;
        int* p = &x2;
        int& r = x;

        cout << "increment pointer vs reference" << endl << endl;

        cout << x << endl;
        cout << hw08::increment_value(x) << endl; // x not changed when passed by value
        cout << x << endl;

        cout << x2 << endl;
        hw08::increment_pointer(p); // p points to x2, x2 updated
        cout << x2 << endl;

        cout << x << endl;
        hw08::increment_reference(r); // r refers to x, x updated
        cout << x << endl;
    }

    // complete the following pointer arithmetic examples
    // indicate if the requested operation is not allowed, why not?
    // Q#2 - pointer arithmetic
    double aDoubles[10];
    double aDoubles2[10];
    double* pd = &aDoubles[5]; // point to aDoubles[5]
    double* pd2 = &aDoubles[7]; // point to aDoubles[7]
    double* pd3 = &aDoubles2[7]; // point to aDoubles[7]

    *pd = 3;
    pd[2] = 4;
    pd[-3] = 5;
    pd2[5] = 6;

    pd = pd + 3; // [2.1] move pd three elements to the right
    pd = pd - 6; // [2.2] move pd six elements to the left
    //pd += 1000;    // [2.3] // ERROR: size array is 10, so move to 1000 element is out of boundary
    //double d = *pd;// [2.4] // ERROR: pd point to address of array, and this is not a double type
    //*pd = 12.34;   // [2.5] // ERROR: can not assign reference to array

    int elements = pd2 - pd; // [2.6] compute the number of elements between pd and pd2 by taking the difference between pd2 and pd
    //int dif2 = pd + pd2; // [2.7] // ERROR: The pointer did not have operator +
    //int dif3 = pd2 - pd3;// [2.8] // ERROR: The pointer did not have operator -

    cout << endl << "print array of doubles forward and backward" << endl << endl;

    // [2.9] print array going forwards
    // p starts at address aDoubles[0], ends at address &aDoubles[9], increment p, cout value pointed to by p
    //for (double* p = // ... ) cout << // ...  << '\n';
    for (double* p = &aDoubles[0]; p < &aDoubles[10]; p++)
        cout << p << '\n';
    cout << endl;

    // [2.10] print array going backwards
    // p starts at address aDoubles[9], ends at address &aDoubles[0], decrement p, cout value pointed to by p
    //for (double* p = // ... ) cout << // ...  << '\n';
    for (double* p = &aDoubles[9]; p >= &aDoubles[0]; p--)
        cout << p << '\n';
    cout << endl;

    double* pd4 = &aDoubles[0];
    double* pd5 = aDoubles + 5;
    double* pd6 = &aDoubles[5];
    double* pd7 = &aDoubles2[5];
    // [2.11] using the equality operator, compare pointers to array elements
    //if (// ...) cout << "pointers point to the same element of the array" << endl;
    if (pd4 == pd6)
        cout << "pointers point to the same element of the array" << endl;
    // [2.12] ... error explain
    //if (pd6 != pd7) cout << "pointers point to the different elements of the array" << endl;
    // ERROR: pd7 point to (aDoubles2) another array with pd6 (aDoubles)

    // complete the following function implementations
    // Q#3 - pointer arithmetic, indexing multidimensional arrays
    double twoDDoubles[hw08::ARRAY_SIZE][hw08::ARRAY_SIZE] = { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 }, { 11, 12, 13, 14, 15 }, { 16, 17, 18, 19, 20 }, { 21, 22,
            23, 24, 25 } };

    cout << endl << "print 2d array of doubles" << endl << endl;

    // print 2ddoubles via subscript operator
    hw08::print_2darray_subscript(twoDDoubles, hw08::ARRAY_SIZE, hw08::ARRAY_SIZE);
    // print 2ddoubles via pointer arithmetic
    hw08::print_2darray_pointer((double*) twoDDoubles, hw08::ARRAY_SIZE, hw08::ARRAY_SIZE);

    // complete the following dynamic allocation examples
    // Q#4 - new, delete operator examples
    {
        int* pi = new int;                              // [4.1] allocate one int
        int* qi = new int[5];                           // [4.2] allocate five ints (an array of 5 ints)
        int& ri = *pi;
        int& ri2 = *qi;
        int*& ri3 = qi;
        ri = 100;
        ri2 = 200;

        double* pd = new double;                        // [4.3] allocate one double
        double* qd = new double[hw08::DYNAMIC_SIZE];    // [4.4] allocate DYNAMIC_SIZE doubles (an array of DYNAMIC_SIZE doubles)

        //pi = pd;  // [4.5] pi points to pd
        // ERROR: pd is double pointer, pi is int pointer
        //pd = pi;  // [4.6] pd points to pi
        // ERROR: can not assign the int pointer to double pointer

        double x = *pd;       // read the (first) object pointed to by pd
        double y = pd[5];     // read the fifth object pointed to by pd
        double z = *(pd + 10);  // read the tenth object pointed to by pd

        cout << endl << "ri, ri2, ri3 before delete" << endl << endl;

        cout << ri << endl;   // ri refers to *pi
        cout << ri2 << endl;  // ri2 refers to *qi
        cout << ri3 << endl;  // ri3 refers to qi

        delete pi;            // [4.7] how are the values of ri, ri2, ri3 affected by delete statement?
                              // ri is null, ri2 and ri3 are unaffected

        delete[] ri3;        // [4.8] how are the values of ri, ri2, ri3 affected by delete statement?
                             // ri3 is deleted, ri and ri2 are unaffected

        cout << endl << "ri, ri2, ri3 after delete" << endl << endl;

        cout << ri << endl;
        cout << ri2 << endl;
        cout << ri3 << endl << endl;
    }

    double* array_of_doubles = hw08::dynamic_allocation_array_doubles(1000);
    // use array_of_doubles here
    delete array_of_doubles; // [4.9] free array, no longer needed

    // Q#5 - dynamic 2d arrays, indexing via subscript operator, pointer arithmetic

    // tic tac toe board is an array of int pointers
    // each int pointer in the board points to a row

    // declare a pointer to an array of int pointers (i.e. a pointer to a pointer of type int)
    int** p_p_tictactoe = new int*[hw08::TIC_TAC_TOE_SIZE];
    p_p_tictactoe[0] = new int;  // [5.1] row1: dynamically allocate int[TIC_TAC_TOE_SIZE], use initializer list to init to {1,0,0}
    p_p_tictactoe[1] = new int;  // [5.2] row2: dynamically allocate int[TIC_TAC_TOE_SIZE], use initializer list to init to {0,1,0}
    p_p_tictactoe[2] = new int;  // [5.3] row3: dynamically allocate int[TIC_TAC_TOE_SIZE], use initializer list to init to {0,0,1}

    // print 2dints via subscript operator
    hw08::print_2darray_dynamic_subscript(p_p_tictactoe, hw08::TIC_TAC_TOE_SIZE, hw08::TIC_TAC_TOE_SIZE);
    // print 2dints via pointer arithmetic
    hw08::print_2darray_dynamic_pointer(p_p_tictactoe, hw08::TIC_TAC_TOE_SIZE, hw08::TIC_TAC_TOE_SIZE);

    // clean up board, go in reverse order of declaration

    // [5.4] delete individual rows (i.e. rows are int arrays, use delete [])
    for (int i = 0; i < hw08::TIC_TAC_TOE_SIZE; i++)
        delete[] p_p_tictactoe[i];
    // [5.5] delete board (board is an array of int pointers, use delete [])
    delete[] p_p_tictactoe;

    return 0;
}

//------------------------------------------------------------------------------

// WRITTEN ANSWERS

// add written answers here ... Q#1 Q#3 Q#5

/**
 * Question 1:
 *  - What is pointer?
 *  A pointer is a variable which contains the address in memory of another variable. We can have a pointer to any variable type.
 *
 *  - What is reference?
 *  A reference variable is an alias, that is, another name for an already existing variable.
 *  Once a reference is initialized with a variable, either the variable name or the reference name may be used to refer to the variable.
 *
 *  - What’s the difference between a pointer and a reference?
 *  A pointer can be re-assigned any number of times while a reference cannot be re-assigned after binding.
 *  Pointers can point nowhere (NULL), whereas a reference always refers to an object.
 *  Can't take the address of a reference like you can with pointers.
 *  There's no "reference arithmetic" (but you can take the address of an object pointed by a reference and do pointer arithmetic on it as in &obj + 5).
 *
 * Question 3:
 *  -  How is the twoDDoubles 2d array laid out in memory?
 *  twoDDoubles is laid out linearly in memory as contiguous rows.
 *
 *  - Why is it necessary to cast twoDDoubles to a double* in the print_2darray_pointer function call
 *  Because the function prints using pointer arithmetic
 *
 * Question 5:
 *  - How is the p_p_tictactoe 2d dynamic array laid out in memory?
 *  The dynamic pointer print function is laid out as a 2d array of int pointers in which each component points to another array of ints. The array is non-contiguous.
 *
 *  - Why do we need to pass a pointer to a pointer of type int in the print_2darray_dynamic_pointer function call
 *  Because the print function prints out a dynamic array which contains int arrays.
 */
