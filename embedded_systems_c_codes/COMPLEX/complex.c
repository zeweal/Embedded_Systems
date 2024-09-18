#include <stdio.h>
#include <assert.h>
#include "complex.h"

/* Creation */ 
//Add your code here
COMPLEX CreateComplex(double real, double imaginary)
{
	COMPLEX result;
	result.real=real;
	result.imaginary=imaginary;
	return result;
}
// End of your code 

/* Destruction */ 
//Add your code here
void DestroyComplex(CPTR complex)
{
	
}
// End of your code 


/* Addition */ 
//Add your code here
COMPLEX AddComplex(CPTR first, CPTR second)
{
		COMPLEX result;
		result.real=first->real+second->real;
		result.imaginary=first->imaginary+second->imaginary;
        //printf("Real= %.2f   Imaginary= %.2f)",result.real,result.imag);
		return result;
}
// End of your code 

/* Subtraction */ 
//Add your code here
COMPLEX SubtractComplex(CPTR first, CPTR second)
{
		COMPLEX result;
		result.real=first->real-second->real;
		result.imaginary=first->imaginary-second->imaginary;
		//printf("Real= %.2f   Imaginary= %.2f)",result.real,result.imag);
		return result;
}

// End of your code 

/* Multiplication */ 
//Add your code here
COMPLEX MultiplyComplex(CPTR first, CPTR second)
{
        COMPLEX result;
		result.real=(first->real * second->real)-(first->imaginary * second->imaginary);
		result.imaginary=(first->real * second->imaginary)+(first->imaginary * second->real);
		//printf("Real= %.2f   Imaginary= %.2f)",result.real,result.imag);
		return result;
		
	
}
// End of your code 

/* Conjugate */ 
//Add your code here
COMPLEX ConjugateComplex(CPTR complex)
{
	COMPLEX result;
	result.real=complex->real;
	result.imaginary=(complex->imaginary)>=0?(complex->imaginary):-(complex->imaginary);
	//printf("Real= %.2f   Imaginary= %.2f)",result.real,result.imag);
	return result;
}
// End of your code 

/* Division */ 
//Add your code here
COMPLEX DivideComplex(CPTR first, CPTR second)
{
	COMPLEX result;
float denominator = (second->real * second->real) + (second->imaginary * second->imaginary);
    result.real = ((first->real * second->real) + (first->imaginary * second->imaginary)) / denominator;
    result.imaginary = ((first->imaginary * second->real) - (first->real * second->imaginary)) / denominator;
    return result;	
}
// End of your code 

/* Printing */ 
//Add your code here
void PrintComplex(CPTR complex)
{
	COMPLEX result;
	printf("Real= %.3f   Imaginary= %.3f)",result.real=complex->real,result.imaginary=complex->imaginary);
}
// End of your code 
