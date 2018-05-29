//
//  main.cpp
//  pic10c_hw1
//
//  Created by Runyu Qian on 5/7/18.
//  Copyright © 2018 Runyu Qian. All rights reserved.
//

#include <iostream>   // std::ostream, std::cout
#include <math.h>


using std::cout;
using std::boolalpha;
using std::string;


template <typename T>
class myvector{
    private:
        T* the_data;
        size_t the_size;
        size_t the_capacity;
        
        static const int INIT_CAP = 10;
        
        
    public:
        // The big 4
        myvector();
        myvector( const myvector<T>& );
        myvector<T>& operator=( const myvector<T>& );
        ~myvector<T>();
        
        // Other members [public]
        bool empty() const;
        size_t size() const;
        size_t capacity() const;
        T front() const;
        T back() const;
        T at( size_t index ) const;
        T& operator[]( size_t index );
        T operator[]( size_t index ) const;
        void dump_data_to( std::ostream& out ) const;
        void dump_data() const;
        void push_back( T new_value );
        void pop_back();
    
    
    
    
    
//        myvector operator + (myvector const &, myvector const &);
//        myvector operator = (myvector const &, myvector const &);
    
    
        myvector<T> operator*(int a);
        myvector<T> operator*(string s);
        myvector<T> operator+(const myvector<T> &);
        T operator*(const myvector<T>& v);
        myvector& operator+=(const myvector<T>& v);
    
        double sqrt1() const;
        bool operator == (const myvector<int> & v) const;
        bool operator != (const myvector<int> & v) const;
        bool operator == (const myvector<string> & v) const;
        bool operator != (const myvector<string> & v) const;
        bool operator < (const myvector<int> & v) const;
        bool operator <= (const myvector<int> & v) const;
        bool operator > (const myvector<int> & v) const;
        bool operator >= (const myvector<int> & v) const;
        
    private:
        //Other members [private]
        void reserve( size_t new_capacity );
}; // end Pic10b::vector
    
    
    /** ************************* THE BIG 4 ************************* **/


template <typename T>
double myvector<T>::sqrt1() const{
    
    T res = NULL;
    for ( int i = 0 ; i < the_size ; ++i ){
        res = res+ the_data[i] * the_data[i];
    }
    return sqrt(res);
    
}


template <typename T>
bool myvector<T>::operator == (const myvector<string> & s) const{
    for ( int i = 0 ; i < the_size ; ++i ){
        if( the_data[i] != s[i]){
            return false;
    }
    }
    return true;
}
    
    
template <typename T>
bool myvector<T>::operator != (const myvector<string> & s) const{
    return !(*
             this==s);
}

template <typename T>
bool myvector<T>::operator == (const myvector<int> & v) const{
    return (this->sqrt1() == v.sqrt1());
}
template <typename T>
bool myvector<T>::operator != (const myvector<int> & v) const{
     return (this->sqrt1() != v.sqrt1());
}
template <typename T>
bool myvector<T>::operator < (const myvector<int> & v) const{
     return (this->sqrt1() < v.sqrt1());
}
template <typename T>
bool myvector<T>::operator <= (const myvector<int> & v) const{
     return (this->sqrt1() <= v.sqrt1());
}
template <typename T>
bool myvector<T>::operator > (const myvector<int> & v) const{
     return (this->sqrt1() > v.sqrt1());
}
template <typename T>
bool myvector<T>::operator >= (const myvector<int> & v) const{
     return (this->sqrt1() >= v.sqrt1());
}


template <typename T>
myvector<T> myvector<T>::operator+(const myvector<T> & v1){
    
    myvector<T> v(v1);
    
    for ( int i = 0 ; i < the_size ; ++i ){
        v[i] = the_data[i] + v1[i];
    }

    return v;
}



template <typename T>
T myvector<T>::operator*(const myvector<T>& v){
    
    T res = NULL;

    for ( int i = 0 ; i < the_size ; ++i ){
        res = res + the_data[i] * v[i];
    }
    
    return res;
    
    
}




template <typename T>
myvector<T>& myvector<T>::operator+=(const myvector<T>& v){
    
    for ( int i = 0 ; i < the_size ; ++i ){
        cout << "" << the_data[i] << '\n';
        the_data[i] = the_data[i]+v[i];
    }
    return *this;
    
}




template <typename T>
myvector<T>::myvector()
    : the_data(nullptr), the_size(0), the_capacity(INIT_CAP) {
        
        the_data = new T[the_capacity];
    }

template <typename T>
myvector<T>::myvector( const myvector<T>& source )
    : the_data(nullptr), the_size(source.the_size),
    the_capacity(source.the_capacity) {
        
        std::cout<<"copy constructor called"<<std::endl;
        
        the_data = new T[the_capacity];
        
        // Deep copy of internal array
        for ( int i = 0 ; i < the_size ; ++i ){
            the_data[i] = source.the_data[i];
        }
    }




template <typename T>
myvector<T> myvector<T>::operator*(int a){
    
    myvector res;

    res.the_data = new T[this->the_capacity];
    res.the_size = this->the_size;
    res.the_capacity = this->the_capacity;
    for ( int i = 0 ; i < the_size ; ++i )
        res.the_data[i] = this->the_data[i]*a;
    
    return res;

}




template <typename T>
myvector<T> myvector<T>::operator*(string s){
    
    myvector res;
    
    res.the_data = new T[this->the_capacity];
    res.the_size = this->the_size;
    res.the_capacity = this->the_capacity;
    for ( int i = 0 ; i < the_size ; ++i )
        res.the_data[i] = this->the_data[i]+s;
    
    return res;
    
}











template <typename T>
myvector<T>& myvector<T>::operator=( const myvector<T>& rhs ) {
    
    
        std::cout<<"Assignment operator called"<<std::endl;
    
        if ( this != &rhs ) {     // Self-assignment?
            // Release old memory and request more
            delete[] the_data;
            the_data = new T[rhs.the_capacity];
            
            // Shallow copy non-pointers
            the_size = rhs.the_size;
            the_capacity = rhs.the_capacity;
            
            // Deep copy internal array
            for ( int i = 0 ; i < the_size ; ++i )
                the_data[i] = rhs.the_data[i];
        }
        return *this;
    }
template <typename T>
    myvector<T>::~myvector(){
        
         std::cout<<"Destructor called"<<std::endl;
        delete[] the_data;
    }
    
    /** *********************** OTHER MEMBERS *********************** **/
template <typename T>
    bool myvector<T>::empty() const {
        return the_size == 0;
    }
template <typename T>
    size_t myvector<T>::size() const {
        return the_size;
    }
template <typename T>
    size_t myvector<T>::capacity() const {
        return the_capacity;
    }
template <typename T>
    T myvector<T>::front() const {
        return *the_data;
    }
template <typename T>
    T myvector<T>::back() const {
        return *(the_data + the_size - 1);
    }
template <typename T>
    T myvector<T>::at( size_t index ) const {
        if ( index < the_size )
            return the_data[index];
        return the_data[0];
    }


template <typename T>
    T& myvector<T>::operator[]( size_t index ){
        return the_data[index];
    }


template <typename T>
    T myvector<T>::operator[]( size_t index ) const {
        return the_data[index];
    }


template <typename T>
    void myvector<T>::dump_data_to( std::ostream& out ) const {
        out << "Vector (dump): ";
        for ( size_t i = 0 ; i < the_capacity ; ++i )
            out << the_data[i] << ' ';
        out << '\n';
    }
template <typename T>
    void myvector<T>::dump_data() const {
        dump_data_to( std::cout );
    }
    
template <typename T>
    void myvector<T>::push_back( T new_value ){
        if ( the_size == the_capacity )
            reserve( the_capacity + 1 );     // `the_data` is reassigned
        
        the_data[the_size++] = new_value;
    }
    
    // This implementation does not shrink the vector (ever)
template <typename T>
    void myvector<T>::pop_back(){
        if ( the_size > 0 )
            --the_size;
    }
    
template <typename T>
    void myvector<T>::reserve( size_t new_capacity ){
        if ( new_capacity > the_capacity ) {
            if ( new_capacity <= 2 * the_capacity )
                new_capacity = 2 * the_capacity;
            
            T* old_location = the_data;
            
            the_data = new T[new_capacity];
            the_capacity = new_capacity;
            
            for ( size_t i = 0 ; i < the_size ; ++i )
                the_data[i] = old_location[i];
            
            delete old_location;
        }
    }




/** ************************ OTHER FUNCTIONS ************************ **/
template <typename T>
std::ostream& operator<<( std::ostream& out, const myvector<T>& v ){
    for ( size_t i = 0 ; i < v.size() ; ++i )
        out << v[i] << ' ';
    return out;
}


/*

template <typename T>
myvector<T> operator+( myvector<T>& v1,  myvector<T>& v2){
    
    return v1+=v2;
    
}


*/


template <typename T>
myvector<T> operator*(int a,  myvector<T>& v){
    
    myvector<T> res;
    
    for (size_t i = 0; i<v.size();++i)
        res.push_back(v[i]*a);
    return res;
    
}




template <typename T>
myvector<T> operator*(myvector<T>& v,int a){
    
    myvector<T> res;
    
    for (size_t i = 0; i<v.size();++i)
        res.push_back(v[i]*a);
    return res;
    
}







template <typename T>
myvector<T> operator*(myvector<T>& v,string s){
    
    myvector<T> res;
    
    for (size_t i = 0; i<v.size();++i)
        res.push_back(v[i]+s);
    return res;
    
}







template <typename T>
myvector<T> operator*(string s,  myvector<T>& v){
    
    myvector<T> res;
    
    for (size_t i = 0; i<v.size();++i)
        res.push_back(s+v[i]);
    return res;
    
}


/*

template <typename T>
myvector<T> operator*( myvector<T>& v, int a){
    for (size_t i = 0; i<v.size();++i)
        v[i] = v[i]*a;
    return v;
}

*/



template <typename T>
void print_vector( const myvector<T>& v ){
    if ( v.empty() )
        std::cout << "Vector is empty\n";
    else
        std::cout << "Vector (contents): " << v << '\n' ;
}








int main(int argc, const char * argv[]) {
    const string itemType = "std::string";
    const int SIZE = 6;
    const string newEntry = "airolG";
    
    cout << "Statement:\tvector<string> v1;\n";
    myvector<string> v1;
    
    cout << "\nAction(s):\tv1 is populated with " << SIZE
    << " " + itemType + " values\n";
    v1.push_back("Abigail");
    v1.push_back("Beatriz");
    v1.push_back("Citlali");
    v1.push_back("Daneli");
    v1.push_back("Elisa");
    v1.push_back("Frida");
    
    cout << "\nStatement:\tvector<string> v2(v1);\n";
    myvector<string> v2(v1);
    
    cout << "\nAction(s):\t3rd entry of v1 is modified (ilaltiC)\n"
    << "\t\tone more " << itemType + " value is pushed back ("
    << newEntry << ")\n" << "\t\tv1 is displayed\n";
    reverse(v1[2].begin(),v1[2].end());
    v1.push_back(newEntry);
    cout << "\tv1 = " << v1 << '\n';
    
    cout << "\nAction(s):\tv2 is displayed\n";
    cout << "\tv2 = " << v2 << '\n';
    
    cout << "\nStatement:\tv2 = v1;\n";
    v2 = v1;
    
    const string prefix = "Name:";
    const string lastName = "Salazar";
    cout << "\nStatement:\tv1 = ( " << prefix << " * v2 ) * "
    << lastName << ";\n";
    v1 = ( prefix * v2 ) * lastName;
    
    cout << "\nAction(s):\tv1 and v2 are displayed\n";
    cout << "\tv1 = " << v1 << '\n';
    cout << "\tv2 = " << v2 << '\n';
    
    
    
    cout << "\nAction(s):\tBoolean comparisons '==' and '!='\n";
    cout << std::boolalpha
    << "\tv1 == v2 is " << ( v1 == v2 ) << '\n'
    << "\tv2 != v1 is " << ( v2 != v1 ) << '\n';
    
    cout << "\nStatement:\treturn 0;\n";
     
    
    return 0;
}
