#include "Bureaucrat.hpp"


int main()
{
	Bureaucrat A("A", 1);
    Bureaucrat B("B", 20);
    Bureaucrat C("C", 100);

    Form Legge1("Legge1", 2 ,2);
    Form Legge2("Legge2", 21, 21);
    Form Legge3("Legge3", 121, 121);

    A.signForm(Legge1);
    A.signForm(Legge2);
    A.signForm(Legge3);

    B.signForm(Legge1);
    B.signForm(Legge2);
    B.signForm(Legge3);

    C.signForm(Legge1);
    C.signForm(Legge2);
    C.signForm(Legge3);

    /* TEST2 (ELIMINA IL PRIMO, USALO DA SOLO)
        Bureaucrat A("A", 1);
        Bureaucrat B("B", 20);
        Bureaucrat C("C", 100);

        Form Legge1("Legge1", 2 ,2);
        Form Legge2("Legge2", 21, 21);
        Form Legge3("Legge3", 121, 121);

        B.signForm(Legge1);
        B.signForm(Legge2);
        B.signForm(Legge3);

        C.signForm(Legge1);
        C.signForm(Legge2);
        C.signForm(Legge3);
    */
}
