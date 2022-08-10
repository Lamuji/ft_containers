#include <vector>
#include <iostream>
#include <iomanip>

// template<typename T = void>
// void	affiche(T){
// 	std::ostream &o;
// 	o << T << std::endl;
// }

// int main (){
// 	affiche(5);
// }



template <class T,typename std::enable_if<std::is_integral<T>::value,T>::type* = nullptr>
void do_stuff(T& t) {
  std::cout << "do_stuff integral\n";
    // an implementation for integral types (int, char, unsigned, etc.)
}

template <class T,typename std::enable_if<std::is_class<T>::value, T>::type* = nullptr>
void do_stuff(T& t) {
    // an implementation for class types
}

// #include <iostream>
// #include <type_traits>

// int main() {
//   std::cout << std::boolalpha;
//   std::cout << "is_integral:" << std::endl;
//   std::cout << "char: " << std::is_integral<char>::value << std::endl;
//   std::cout << "int: " << std::is_integral<int>::value << std::endl;
//   std::cout << "float: " << std::is_integral<float>::value << std::endl;
//   return 0;
// }

// enable if sera utilise en parametre d'un template afin de faire comprendre au compilateur quel fonction parmi plusieurs ayant le meme nom il utilisera ( car elle sera effectivement adaptee )
// il prend un boolean en premier parametre pour savoir si le type quon passera sera bien parmi des type "acceptable" par le template.
//  exemple de bool = std::is_integral<T>::value , std::is_class<T>::value... 
//

// une fonction portant un template qui aura un parametre Enable_if sera enfait selectionne ou non par le compilateur selon si elle rempli
// ou pas les condition necessaire quon aura voulu.




// EXEMPLE  //

template <class T, typename std::enable_if<std::is_integral<T>::value, T>::type* = nullptr>
void do_stuff(T& t) {
	std::cout << "do_stuff integral\n";
    // an implementation for integral types (int, char, unsigned, etc. sont des integral) 
}

template <class T, typename std::enable_if<std::is_class<T>::value, T>::type* = nullptr>
void do_stuff(T& t) {
    // an implementation for class types, en sachant qu'une struct est considerer comme une classe,
	// donc si on met un type struct, classe,  a "is_class<T>::value" ca valeur sera True. 
	// par contre, une union, ou une "enum class" ne sont pas considere comme des classes.
}
// Note SFINAE at work here. When we make the call do_stuff(int var), the compiler selects 
// the first overload: since the condition std::is_integral<int> is true, the specialization of 
// struct enable_if for true is used, and its internal type is set to int. The second overload is
//  omitted because without the true specialization (std::is_class<int> is false) the general form 
//  of struct enable_if is selected, and it doesn't have a type, so the type of the argument results
//   in a substitution failure.

// ca veut dire que si on prend la fonction et quon lui fout un int : do_stuff(int x), le compilo 
// choisira cette version de la fonction car le parametre is_intgral du template de cette meme fonction
// renverra true. evidemment un int n'est pas une class.


// enable_if peut etre utiliser ailleurs qu'en parametre d;un template, par ex, 
// vector a plusieurs constructeur et on va en choisir 2 : 
// std::vector<int> v1(4, 8);
// std::vector<int> v2(std::begin(v1), std::end(v1));
// 2 formes de constructeurs prenant 2 argeuments en parametre.

// voila comment les constructeurs peuvent etre defini ( apparemment ya des allocator dedans mais on les ignore) : 

template <typename T>
class vector {

    vector(size_type n, const T val);

    template <class InputIterator>
    vector(InputIterator first, InputIterator last);

    ...
}

// mais a la declaration le compilateur va choisir la 2e definition (avec le template)
// car elle prend un type generique "InputIterator" qui match avec nimporte quel type
// alors que le premier constructeur prend unn size_type et un type Generique (T val)
// le compilateur va alors logiquement choisir celle qui sera plus propice a accepter peu importe le type, 
// eet donc le constructeur avec les 2 types generique. 
// vu que 4 est considerer comme un int et non cpmme un "size_type".

// enable_if servira a contrer ce soucis en ajoutnt des conditions :

template <class _InputIterator>
vector(_InputIterator __first, typename enable_if<__is_input_iterator<_InputIterator>::value &&
                          !__is_forward_iterator<_InputIterator>::value &&
                          ... more conditions ...
                          _InputIterator>::type __last);



