#include <iostream>

namespace View
{
//    all ui related
    //EVERYTHING UI RELATED
    class UI{
    public:
        void prompt(std::string s)
        {
            std::cout << s << std::endl;
        }
        void prompt(int i)
        {
            std::cout << i << std::endl;
        }

        template <typename T>
        T getInput()
        {
            T i;
            std::cin >> i;
            return i;
        }
    };

}
namespace Model{
//    all storage related
    class storage{
    private :
        int i;
    public:
        void store(int n)
        {
            i = n;
        }
        int retrieve()
        {
            return i;
        }
    };

}
namespace Controller{
//    all business logic related
    //EVERYTHING THAT IS BUSINESS LOGIC RELATED
    class Logic{
        View::UI* ui;
        Model::storage* s;

    public:
        Logic(View::UI* _ui, Model::storage* _s)
        {
            this->ui = _ui;
            this->s = _s;
welcomeView();
//            doLogic();
        }
//        void doString(){
//            //ask user for a number using the ui object (view)
//            ui->prompt("Enter a string");
//            std::string i = ui->getInput<std::string>();
//
//            //store that nuber from teh storage object (model)
//            s->store(i);
//
//            //retreive that number from the storage object (model)
//            std::string j = s->retrieve();
//
//            //display that number to the user using the ui object (view)
//            ui->prompt("Here is the string you entered:");
//            ui->prompt(j);
//            ui->prompt("\n");
//        }
        void welcomeView(){
            ui->prompt("stockedUp \nPress 1 to login \nPress 2 to register");
            int choice = ui->getInput<int>();

            s->store(choice);

            int j = s->retrieve();
            if(j == 1){
                loginView();
            }
            else if(j == 2){
//                registerView();
            }
            else{
                ui->prompt("Invalid choice");
                welcomeView();
            }
        }
        void loginView() {
            std::string userName;
            std::string password;

            ui->prompt("Login View");
            ui->prompt("Enter username: ");
            userName = ui->getInput<std::string>();
            ui->prompt("Enter password: ");
            password = ui->getInput<std::string>();
        }
        void registerView(){}
        void doLogic(){
            //ask user for a number using the ui object (view)
            ui->prompt("Enter a number");
            int i = ui->getInput<int>();

            //store that nuber from teh storage object (model)
            s->store(i);

            //retreive that number from the storage object (model)
            int j = s->retrieve();

            //display that number to the user using the ui object (view)
            ui->prompt("Here is the number you entered:");
            ui->prompt(j);
            ui->prompt("\n");



        }

    };


}
namespace Domain{
//    all domain related, all actor entities
    class User{
    private:
        int userId;
        std::string username;
        std::string password;
    public:
        User(int userId,const std::string& username,const std::string& password){
            this->username = username;
            this->password = password;
        }
        void setUserId(int userId){
            this->userId = userId;
        }
        int getUserId() const{
            return userId;
        }
        void setUsername(const std::string& username){
            this->username = username;
        }
        std::string getUsername() const{
            return username;
        }

        void setPassword(const std::string& password){
            this->password = password;
        }
        std::string getPassword() const{
            return password;
        }
    };
    class Item{
    private:
        int itemId;
        std::string name;
        int quantity;
        std::string purchaseDate;
        std::string expiryDate;
    public:
        Item(int itemId,const std::string& name,int quantity,const std::string& purchaseDate,const std::string& expiryDate){
            this->itemId = itemId;
            this->name = name;
            this->quantity = quantity;
            this->purchaseDate = purchaseDate;
            this->expiryDate = expiryDate;
        }
        void setItemId(int itemId){
            this->itemId = itemId;
        }
        int getItemId() const{
            return itemId;
        }
        void setName(const std::string& name){
            this->name = name;
        }
        std::string getName() const{
            return name;
        }
        void setQuantity(int quantity){
            this->quantity = quantity;
        }
        int getQuantity() const{
            return quantity;
        }
        void setPurchaseDate(const std::string& purchaseDate){
            this->purchaseDate = purchaseDate;
        }
        std::string getPurchaseDate() const{
            return purchaseDate;
        }
        void setExpiryDate(const std::string& expiryDate){
            this->expiryDate = expiryDate;
        }
        std::string getExpiryDate() const{
            return expiryDate;
        }
    };


}
int main() {
    View :: UI u;
    Model :: storage s;

    Controller :: Logic l(&u, &s);

    return 0;
}
