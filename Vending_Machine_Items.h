#ifndef VENDING_MACHINE_ITEMS_H
#define VENDING_MACHINE_ITEMS_H


class Vending_Machine_Items
{
public:
    Vending_Machine_Items();
    void Vending_Machine_Money_input();
    void Vending_Machine_Money_repeat_input();
    void Vending_Machine_Choices_Items();
    void Vending_Machine_Money();
    void Vending_Machine_Anther_choice();
    void break_fun();
    void setnumber();

    float new_temp;
    int number ;    /// Anther Choice Function .
    int counter = 10;
        int item_Choice_number;

private:
    float input_money;
//        int item_number_1 = 10 , item_number_2 = 10 , item_number_3 = 10 , item_number_4 = 10 , item_number_5 = 10 , item_number_6 = 10
//                , item_number_7 = 10 , item_number_8 = 10 , item_number_9 = 10 , item_number_10 = 10 ;

    float temp;
    float number_of_item;
    float repeat_input;

};

#endif // VENDING_MACHINE_ITEMS_H
//int new_input;
//        cout << "1- IF you Want to Enter New Money .\n2- IF You To End Program .\nEnter Your Choice :";
//        cin >> new_input;
//        if (new_input == 1){
//            object.Vending_Machine_Money_repeat_input();
//        }
//        while(new_input != 1 ){break;}
