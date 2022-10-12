#include "vector.hpp"

namespace ft
{
    template< class T, class Container = ft::vector<T> >
    class stack{

        public :

            typedef Container                           container_type;
            typedef typename Container::value_type      value_type;
            typedef typename Container::size_type       size_type;
            typedef typename Container::reference       reference;
            typedef typename Container::const_reference const_reference;

        private :

        public :

            //******************************* constructors **************************************//

            explicit stack( const Container& cont = Container() ){
                
            }

            stack( const stack& other ){

            }
    };
}