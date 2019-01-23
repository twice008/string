#include <iostream>
#include <string.h>
using namespace std;

                class MyString
                {   
                private:
                char *str;
                int length;
                
                public:
                        
                        MyString()
                        {
                            str = nullptr;
                            length = 0;
                        };
                        
                        
                        MyString(const char *str) //конструктор
                        {
                            length = strlen(str); // длина слова
                            
                            this->str = new char [length+1]; // выделяем новое место под слово
                            
                            for(int i = 0; i<length; i++) //заполняем массив chars
                            {
                                this->str[i] = str[i];
                            }
                            
                            this->str[length] = '\0'; //добавляем в конец термирующий ноль
                        };
                        
                        
                        bool operator==(const MyString &other) //конструктор сравнения
                        {
                            if(this->length!=other.length)
                            {
                                return false;
                            }
                            
                            for(int i = 0; i< this->length; i++)
                            {
                               if(this->str[i]!=other.str[i])
                               {
                                   return false;
                               }
                            }
                            
                            return true;
                        }
                        
                        
                        bool operator!=(const MyString &other) //конструктор сравнения
                        {
                            return !(this->operator==(other));
                        }
                        
                        
                        MyString(const MyString &other) //конструктор копирования
                        {
                            length = strlen(other.str); //передаем длину аргументного объекта в настоящий
                            
                            this->str = new char [length+1]; //выделяем память под настоящий объект
                            
                            for(int i = 0; i<length; i++) //заполняем настоящий объект из аргументного
                            {
                                this->str[i] = other.str[i];
                            }
                            
                            this->str[length] = '\0'; //добавляем в конец термирующий ноль
                            
                        }
                        
                        
                        MyString &operator=(const MyString &other) //перегрузка оператора =
                        {
                            if(this->str!=nullptr) //проверка на утечку
                            {
                                delete[] str;
                            }
                            
                            length = strlen(other.str);  //передаем длину аргументного объекта в настоящий
                            
                            this->str = new char [length+1]; //выделяем память под настоящий объект
                            
                            for(int i = 0; i<length; i++) //заполняем настоящий объект из аргументного
                            {
                                this->str[i] = other.str[i];
                            }
                            
                            this->str[length] = '\0'; //добавляем в конец термирующий ноль
                            
                            return *this; //возвращаем значение нстоящего объекта
                        }
                        
                        
                        MyString operator+(const MyString &other) // перегрузка оператора + (конкатенация)
                        {
                            MyString newStr; // создаем нвоый объект в котором будет результат
                            
                            int thislength = strlen(this->str);  // длина настоящего объекта
                            
                            int otherlength = strlen(other.str);  // длина аргументного объекта
                            
                            newStr.length = thislength+otherlength;  // для метода Length
                            
                            newStr.str = new char [thislength+otherlength+1]; //выделяем память под созданный объект
                            
                            int i = 0; // выносим иттератор для продолжение конкатенации
                            
                            for(;i<thislength; i++) // заполнение нового объекта 0-50%
                            {
                                newStr.str[i] = this->str[i];
                            }
                            
                            for(int j = 0; j<otherlength; j++, i++) // заполнение нового объекта 50-100%
                            {
                                newStr.str[i] = other.str[j];
                            }
                            
                            newStr.str[thislength+otherlength] = '\0';  //добавляем в конец термирующий ноль
                            
                           return newStr; // возвращаем объект
                        }
                        
                        
                       MyString(MyString &&other) //конструктор перемещения
                        {
                            this->length = other.length;
                            
                            this->str = other.str; //ссылаемся на сущетсвующий объект
                            
                            other.str = nullptr;
                        }
                        
                        
                        ~MyString()
                        {
                          delete[] str;  
                        };
                        
                        
                        void Print() // метод print
                        {
                            cout<<str<<endl;
                        }
                        
                        
                        int Length() // метод Length
                        {
                            return length;    
                        };
                        
                        
                        char& operator[](int index)
                        {
                           return this->str[index]; 
                        }
                    
                };

int main()
{
    MyString str ("Hello ");

    MyString str2 ("World!");
    
    MyString result;
    
    result = str+str2;
    
    result.Print();
    
    cout<<str.Length()<<endl;
    cout<<str2.Length()<<endl;
    cout<<result.Length()<<endl;

    bool equal = atr == str;
    return 0;
}


