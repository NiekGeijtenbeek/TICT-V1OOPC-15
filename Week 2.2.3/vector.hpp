#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

///@file

/// \brief
/// vector ADT
/// \details
/// This is an ADT that implements vector values.
/// The X, and Y of an vector (X,Y) are stored as two integers.
/// A constructor and some operators are provided.

class vector {
public:
    int x;
    int y;
    /// \brief
    /// Constructor for a vector
    /// \details
    /// The constructor initializes a vector from the two given integers.
    /// And stores them as a vector ADT (X,Y).
    vector( int x = 0, int y = 0 ):
        x( x ), y( y )
    {}
    
    /// \brief
    /// Plus assignment for a vector
    /// \details
    /// This operator returns the sum of the lhs vector with the rhs vector.
    /// The value is returned in the lhs vector.
    vector & operator+=( const vector & rhs );
    
    /// \brief
    /// Binary plus for a vector
    /// \details
    /// The operator returns the sum of the lhs and rhs, and returns them as a new vector.
    vector operator+( const vector & rhs) const;
    

    /// \brief
    /// Multiply and assign operator for a vector
    /// \details
    /// Multiplies a vector (lhs and constant integer) and returns the result into lhs;
    vector & operator*=( const int rhs );
    
    /// \brief
    /// Mutliply operator for a vector
    
    /// \detais
    /// Mutliplies vector with an integer and returns the result as a new vector.
    vector operator*( const int rhs ) const;
    


/// \brief
/// Print a vector in a readable fashion.
friend std::ostream & operator<<( std::ostream & lhs, vector pos ){
   lhs << "(" << pos.x << "," << pos.y << ")";
   return lhs;
}
   
};

/// \brief
/// Mutliply operator for a vector
    
/// \detais
/// Mutliplies vector with an integer and returns the result as a new vector.
vector operator*(const int lhs, const vector & rhs);
#endif // VECTOR_HPP