
#include "class.h"
const string product_file = "product.txt";

const string user_file = "users.txt";


//  MODULE 1  -  Muhammad Anas Majid

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


string get_string_input(string prompt)
{
    string value;
    while (true)

    {
        cout << prompt;
        getline(cin, value);

        if (value != "")
            return value;
        cout << "   Input cannot be empty. Try again." << endl;

    }
}



int get_int_input(string prompt, int min_val, int max_val)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            cin.ignore(1000, '\n');
            if (value >= min_val && value <= max_val)
                return value;
            cout << "   Must be between " << min_val << " and " << max_val << ". Try again." << endl;
        }
        else
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "   Please enter a whole number." << endl;
        }
    }
}



double get_double_input(string prompt, double min_val, double max_val)
{

    double value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {

            cin.ignore(1000, '\n');
            if (value >= min_val && value <= max_val)
                return value;
            cout << "   Must be between " << min_val << " and " << max_val << ". Try again." << endl;

        }
        else
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "   Please enter a number." << endl;
        }
    }
}



bool is_valid_username(string s)
{
    if (s == "") return false;

    for (int i = 0; i < (int)s.size(); i++)
    {
        char c = s[i];
        bool is_letter = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
        bool is_digit = (c >= '0' && c <= '9');
        bool is_under = (c == '_');
        if (!is_letter && !is_digit && !is_under)
            return false;
    }

    return true;
}

bool is_valid_password(string s)
{
    if ((int)s.size() < 6) return false;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            return true;
    }
    return false;
}


class product
{
private:
    int    product_id;
    double price;
    int    quantity;
    string product_name;
    string product_type;

public:

    // default construcutor

    product()
    {
        product_id = 0;
        price = 0.0;
        quantity = 0;
        product_name = "unknown";
        product_type = "product";
    }

    // parametrized constructor

    product(int id, string name, double p, int qty, string type)
    {
        product_id = id;
        product_name = name;
        price = p;
        quantity = qty;
        product_type = type;
    }

    //copy constructor

    product(const product& other)
    {
        product_id = other.product_id;
        product_name = other.product_name;
        price = other.price;
        quantity = other.quantity;
        product_type = other.product_type;
    }

   

    product& operator=(const product& other)
    {
        if (this != &other)
        {
            product_id = other.product_id;
            product_name = other.product_name;
            price = other.price;
            quantity = other.quantity;
            product_type = other.product_type;
        }
        return *this;
    }

    // virtual destructor 

    virtual ~product() {}

    

    void set_product_id(int id)
    {
        if (id > 0)

        {
            product_id = id;
        }
        else
        {
            cout << "   Error: ID must be positive." << endl;

        }
    }

    void set_price(double p)
    {
        if (p >= 0)
        {
            price = p;
        }
        else
        {
            cout << "   Error: Price cannot be negative." << endl;

        }
    }

    void set_quantity(int qty)
    {
        if (qty >= 0)
        {
            quantity = qty;
        }

        else
        {
            cout << "   Error: Quantity cannot be negative." << endl;
        }

    }

    void set_product_name(string name)
    {
        product_name = name;
    }

    void set_product_type(string type)
    {
        product_type = type;
    }

    

    int    get_product_id()   const { return product_id; }

    double get_price()        const { return price; }

    int    get_quantity()     const { return quantity; }

    string get_product_name() const { return product_name; }

    string get_product_type() const { return product_type; }

    

    double calculate_value() const
    {
        return price * quantity;
    }

    // virtual functions 

    virtual void display_status()
    {
        cout << "  ----------------------------------------" << endl;
        cout << "  Product ID   : " << product_id << endl;
        cout << "  Name         : " << product_name << endl;
        cout << "  Type         : " << product_type << endl;
        cout << "  Price        : Rs " << fixed << setprecision(2) << price << endl;
        cout << "  Quantity     : " << quantity << endl;
        cout << "  Total Value  : Rs " << fixed << setprecision(2) << calculate_value() << endl;
    }

    virtual double calculate_risk()
    {
        return 0.0;
    }

    virtual void apply_discount(double percent)
    {
        price = price - (price * percent / 100.0);
        cout << "   Discount applied. New price: Rs " << fixed << setprecision(2) << price << endl;
    }

    // operator overloading 

    

    bool operator==(const product& other) const
    {
        return (product_id == other.product_id);
    }

    friend ostream& operator<<(ostream& out, const product& p)
    {
        out << "  ID: " << p.product_id
            << " | Name: " << p.product_name
            << " | Type: " << p.product_type
            << " | Price: Rs " << fixed << setprecision(2) << p.price
            << " | Qty: " << p.quantity;

        return out;
    }

    

    virtual void save_to_file(ofstream& file)
    {
        file << product_type << "\n"
            << product_id << "\n"
            << product_name << "\n"
            << price << "\n"
            << quantity << "\n";
    }
};



//  MODULE 2  -  Hasnat



class electronic_product : public product
{
private:
    int    voltage;
    int    warranty;
    string brand_name;


    char* brand_ptr;

    

    void copy_brand(string b)
    {
        brand_name = b;
        delete[] brand_ptr;
        brand_ptr = new char[brand_name.size() + 1];

        for (int i = 0; i <= (int)brand_name.size(); i++)
        {
            brand_ptr[i] = brand_name[i];
        }
    } 

public:

    // default constructor

    electronic_product() : product()
    {
        voltage = 220;
        warranty = 12;
        brand_name = "generic";
        brand_ptr = new char[brand_name.size() + 1];

        for (int i = 0; i <= (int)brand_name.size(); i++)
        {
            brand_ptr[i] = brand_name[i];
        }
    }

    // parameterised constructor

    electronic_product(int id, string name, double price, int qty,
        int volt, int war, string brand)
        : product(id, name, price, qty, "electronic")
    {
        voltage = volt;
        warranty = war;
        brand_ptr = nullptr;
        copy_brand(brand);
    }

    //copy constructor 

    electronic_product(const electronic_product& other) : product(other)
    {
        voltage = other.voltage;
        warranty = other.warranty;
        brand_ptr = nullptr;
        copy_brand(other.brand_name);
    }

    // assignment operator

    electronic_product& operator=(const electronic_product& other)
    {
        if (this != &other)
        {
            product::operator=(other);
            voltage = other.voltage;
            warranty = other.warranty;
            copy_brand(other.brand_name);
        }

        return *this;
    }

    // destructor  


    ~electronic_product()
    {
        delete[] brand_ptr;
        brand_ptr = nullptr;
    }

   
    void set_voltage(int v)
    {
        voltage = v;
    }

    void set_warranty(int w)
    {
        warranty = w;
    }

    void set_brand(string b)
    {
        copy_brand(b);
    }


    int    get_voltage()  const { return voltage; }

    int    get_warranty() const { return warranty; }

    string get_brand()    const { return brand_name; }


    void test_hardware()
    {
        cout << "  Hardware Test" << endl;

        if (voltage == 220)
        {
            cout << "   Voltage 220V - Compatible with Pakistan standard." << endl;
        }
        else
        {
            cout << "   Voltage " << voltage << "V - Check compatibility." << endl;
            cout << "   Warranty: " << warranty << " months." << endl;
        }
    }


    void display_status() override
    {
        product::display_status();

        cout << "  Brand        : " << brand_name << endl;
        cout << "  Voltage      : " << voltage << "V" << endl;
        cout << "  Warranty     : " << warranty << " months" << endl;
    }

    double calculate_risk() override
    {
        if (voltage > 220)

            return 2.0;

        return 1.0;
    }


    void save_to_file(ofstream& file) override
    {
        file << "electronic" << "\n"
            << get_product_id() << "\n"
            << get_product_name() << "\n"
            << get_price() << "\n"
            << get_quantity() << "\n"
            << voltage << "\n"
            << warranty << "\n"
            << brand_name << "\n";
    }
};


// CLASS 3 : fragile electronics  


class fragile_electronics : public electronic_product
{

private:

    int    fragility_rating;
    string packaging_type;

public:

    // default constructor

    fragile_electronics() : electronic_product()
    {
        fragility_rating = 5;
        packaging_type = "bubble_wrap";
        set_product_type("fragile_electronic");
    }

    // parameterised constructor

    fragile_electronics(int id, string name, double price, int qty,
        int volt, int war, string brand,
        int frag_rating, string pkg_type)
        : electronic_product(id, name, price, qty, volt, war, brand)
    {

        fragility_rating = frag_rating;
        packaging_type = pkg_type;
        set_product_type("fragile_electronic");

    }

    

    void set_fragility_rating(int r)
    {
        if (r >= 1 && r <= 10)
        {
            fragility_rating = r;
        }
        else
        {
            cout << "   Fragility rating must be 1-10." << endl;
        }
    }

    void set_packaging_type(string p) { packaging_type = p; }



    int    get_fragility_rating() const { return fragility_rating; }

    string get_packaging_type()   const { return packaging_type; }


    double calculate_shipping_risk()
    {
        return fragility_rating * 10.0;
    }

    

    void display_status() override
    {
        electronic_product::display_status();

        cout << "  Fragility    : " << fragility_rating << "/10" << endl;
        cout << "  Packaging    : " << packaging_type << endl;
        cout << "  Ship Risk    : " << calculate_shipping_risk() << "%" << endl;
    }


    double calculate_risk() override
    {
        return calculate_shipping_risk();
    }


    void apply_discount(double percent) override
    {
        double actual_discount = percent / 2.0;
        cout << "   Fragile item: discount reduced to " << actual_discount << "%" << endl;
        product::apply_discount(actual_discount);
    }


    void save_to_file(ofstream& file) override
    {
        file << "fragile_electronic" << "\n"
            << get_product_id() << "\n"
            << get_product_name() << "\n"
            << get_price() << "\n"
            << get_quantity() << "\n"
            << get_voltage() << "\n"
            << get_warranty() << "\n"
            << get_brand() << "\n"
            << fragility_rating << "\n"
            << packaging_type << "\n";
    }
};


//  MODULE 3  -  Talha


class grocery_product : public product
{
private:

    int  calories;
    bool is_halal;

public:

    // default constructor

    grocery_product() : product()
    {
        calories = 0;
        is_halal = true;
        set_product_type("grocery");
    }

    // parameterised constructor


    grocery_product(int id, string name, double price, int qty, int cal, bool halal)
        : product(id, name, price, qty, "grocery")
    {
        calories = cal;
        is_halal = halal;
    }
    

    void set_calories(int c) { calories = c; }

    void set_halal(bool h) { is_halal = h; }


    int  get_calories() const { return calories; }

    bool get_halal()    const { return is_halal; }


    void check_safety()
    {
        cout << "  Safety Check" << endl;
        cout << "  Halal Status : " << (is_halal ? "Halal Certified" : "NOT Halal") << endl;
        cout << "  Calories     : " << calories << " per serving" << endl;

        if (calories > 500)
        {
            cout << "   High calorie product - add nutrition warning." << endl;
        }
    }


    void display_status() override
    {
        product::display_status();

        cout << "  Calories     : " << calories << endl;
        cout << "  Halal        : " << (is_halal ? "Yes" : "No") << endl;
    }

    
    double calculate_risk() override
    {
        return 1.5;
    }

    

    void save_to_file(ofstream& file) override
    {
        file << "grocery" << "\n"
            << get_product_id() << "\n"
            << get_product_name() << "\n"
            << get_price() << "\n"
            << get_quantity() << "\n"
            << calories << "\n"
            << is_halal << "\n";
    }
};


// CLASS 5 : perishable grocery  


class perishable_grocery : public grocery_product
{

private:

    string expiry_date;    
    double storage_temp;   

public:

    // default constructor

    perishable_grocery() : grocery_product()
    {
        expiry_date = "2025-12-31";
        storage_temp = 4.0;
        set_product_type("perishable_grocery");
    }

    // parameterised constructor

    perishable_grocery(int id, string name, double price, int qty,
        int cal, bool halal, string exp_date, double temp)
        : grocery_product(id, name, price, qty, cal, halal)
    {

        expiry_date = exp_date;
        storage_temp = temp;
        set_product_type("perishable_grocery");

    }


    void set_expiry_date(string d)
    {
        expiry_date = d;
    }

    void set_storage_temp(double t)
    {
        storage_temp = t;
    }


    string get_expiry_date()  const { return expiry_date; }

    double get_storage_temp() const { return storage_temp; }


    bool check_expiry()
    {
        string current_date = "2025-01-01";  

        if (expiry_date < current_date)
        {
            cout << "   EXPIRED: " << get_product_name()
                << " expired on " << expiry_date << endl;
            return true;
        }

        else
        {
            cout << "   Product is within expiry: " << expiry_date << endl;
            return false;
        }
    }


    void display_status() override
    {
        grocery_product::display_status();
        cout << "  Expiry Date  : " << expiry_date << endl;
        cout << "  Storage Temp : " << storage_temp << " Celsius" << endl;
        check_expiry();
    }


    double calculate_risk() override
    {
        if (check_expiry())
            return 9.5;
        return 2.0;
    }


    void apply_discount(double percent) override
    {
        cout << "   Perishable item: extra 10% added to discount." << endl;
        product::apply_discount(percent + 10.0);
    }


    void save_to_file(ofstream& file) override
    {
        file << "perishable_grocery" << "\n"
            << get_product_id() << "\n"
            << get_product_name() << "\n"
            << get_price() << "\n"
            << get_quantity() << "\n"
            << get_calories() << "\n"
            << get_halal() << "\n"
            << expiry_date << "\n"
            << storage_temp << "\n";
    }
};


// CLASS 6 : non_perishable   

class non_perishable : public grocery_product
{

private:

    int    shelf_life_years;
    string preservative_level;   

public:

    // default constructor

    non_perishable() : grocery_product()
    {
        shelf_life_years = 1;
        preservative_level = "low";
        set_product_type("non_perishable");
    }

    // parameterised constructor

    non_perishable(int id, string name, double price, int qty,
        int cal, bool halal, int shelf_years, string pres_level)
        : grocery_product(id, name, price, qty, cal, halal)
    {
        shelf_life_years = shelf_years;
        preservative_level = pres_level;
        set_product_type("non_perishable");
    }


    void set_shelf_life(int y)
    {
        shelf_life_years = y;
    }

    void set_preservative_level(string p)
    {
        preservative_level = p;
    }


    int    get_shelf_life()         const { return shelf_life_years; }

    string get_preservative_level() const { return preservative_level; }


    void get_storage_instructions()
    {
        cout << "  Storage Instructions" << endl;
        cout << "  Shelf Life    : " << shelf_life_years << " years" << endl;
        cout << "  Preservatives : " << preservative_level << endl;

        if (preservative_level == "low")
        {
            cout << "   Store in cool and dry place. Avoid humidity." << endl;
        }

        else if (preservative_level == "medium")
        {
            cout << "   Store at room temperature. Keep sealed." << endl;
        }

        else
        {
            cout << "   No special storage needed. Long shelf life." << endl;
        }
    }

    
    void display_status() override
    {
        grocery_product::display_status();
        cout << "  Shelf Life   : " << shelf_life_years << " years" << endl;
        cout << "  Preservative : " << preservative_level << endl;
    }

    
    double calculate_risk() override
    {
        return 0.5;
    }

   
    void save_to_file(ofstream& file) override
    {
        file << "non_perishable" << "\n"
            << get_product_id() << "\n"
            << get_product_name() << "\n"
            << get_price() << "\n"
            << get_quantity() << "\n"
            << get_calories() << "\n"
            << get_halal() << "\n"
            << shelf_life_years << "\n"
            << preservative_level << "\n";
    }
};


// CLASS 7 : clothing_product  

class clothing_product : public product
{
private:
    string size;
    string fabric;
    string gender;

public:

    // default constructor

    clothing_product() : product()
    {
        size = "M";
        fabric = "cotton";
        gender = "unisex";
        set_product_type("clothing");
    }

    // parameterised constructor

    clothing_product(int id, string name, double price, int qty,
        string sz, string fab, string gen)
        : product(id, name, price, qty, "clothing")
    {
        size = sz;
        fabric = fab;
        gender = gen;
    }


    void set_size(string s)
    {
        size = s;
    }

    void set_fabric(string f)
    {
        fabric = f;
    }

    void set_gender(string g)
    {
        gender = g;
    }


    string get_size()   const { return size; }

    string get_fabric() const { return fabric; }

    string get_gender() const { return gender; }


    void fit_guide()
    {
        cout << "  Fit Guide" << endl;
        cout << "  Size   : " << size << endl;
        cout << "  Fabric : " << fabric << endl;
        cout << "  Gender : " << gender << endl;
        if (size == "XL" || size == "XXL")
        {
            cout << "   Tip: Oversized fit - consider ordering one size down." << endl;
        }

        else
        {
            cout << "   Tip: True to size. Standard fit." << endl;
        }
    }


    void display_status() override
    {
        product::display_status();
        cout << "  Size         : " << size << endl;
        cout << "  Fabric       : " << fabric << endl;
        cout << "  Gender       : " << gender << endl;
    }


    double calculate_risk() override
    {
        return 0.2;
    }

   
    void save_to_file(ofstream& file) override
    {
        file << "clothing" << "\n"
            << get_product_id() << "\n"
            << get_product_name() << "\n"
            << get_price() << "\n"
            << get_quantity() << "\n"
            << size << "\n"
            << fabric << "\n"
            << gender << "\n";
    }
};

//  MODULE 4  -  Mohid Malik


class supplier
{
private:

    int    supplier_id;
    string supplier_name;
    string contract_terms;
    string contact_number;
    double discount_offered;

public:

    // default constructor

    supplier()
    {
        supplier_id = 0;
        supplier_name = "unknown";
        contract_terms = "standard";
        contact_number = "0000-0000000";
        discount_offered = 0.0;
    }

    // parameterised constructor

    supplier(int id, string name, string terms, string contact, double disc)
    {
        supplier_id = id;
        supplier_name = name;
        contract_terms = terms;
        contact_number = contact;
        discount_offered = disc;
    }

    

    void set_supplier_id(int id)
    {
        supplier_id = id;
    }

    void set_supplier_name(string n)
    {
        supplier_name = n;
    }

    void set_contract_terms(string t)
    {
        contract_terms = t;
    }

    void set_contact(string c)
    {
        contact_number = c;
    }

    void set_discount(double d)
    {
        discount_offered = d;
    }



    int  get_supplier_id()   const { return supplier_id; }

    string get_supplier_name() const { return supplier_name; }

    string get_contract()      const { return contract_terms; }

    string get_contact()       const { return contact_number; }

    double get_discount()      const { return discount_offered; }


    void order_restock(string product_name, int qty_needed)
    {
        cout << "  Restock Order" << endl;
        cout << "  Supplier   : " << supplier_name << endl;
        cout << "  Product    : " << product_name << endl;
        cout << "  Qty Needed : " << qty_needed << endl;
        cout << "  Contact    : " << contact_number << endl;
        cout << "  Terms      : " << contract_terms << endl;
        cout << "   Restock order sent to supplier." << endl;
    }


    void generate_invoice(string product_name, int qty, double unit_price)
    {
        double subtotal = qty * unit_price;
        double discount = subtotal * discount_offered / 100.0;
        double final_amount = subtotal - discount;

        cout << "  ===== SUPPLIER INVOICE =====" << endl;
        cout << "  Supplier   : " << supplier_name << endl;
        cout << "  Product    : " << product_name << endl;
        cout << "  Quantity   : " << qty << endl;
        cout << "  Unit Price : Rs " << fixed << setprecision(2) << unit_price << endl;
        cout << "  Subtotal   : Rs " << fixed << setprecision(2) << subtotal << endl;
        cout << "  Discount   : " << discount_offered << "% = Rs " << discount << endl;
        cout << "  Total Due  : Rs " << fixed << setprecision(2) << final_amount << endl;
        cout << "  ============================" << endl;
    }


    void display_supplier()
    {
        cout << "  ----------------------------------------" << endl;
        cout << "  Supplier ID : " << supplier_id << endl;
        cout << "  Name        : " << supplier_name << endl;
        cout << "  Contact     : " << contact_number << endl;
        cout << "  Terms       : " << contract_terms << endl;
        cout << "  Discount    : " << discount_offered << "%" << endl;
    }


    friend ostream& operator<<(ostream& out, const supplier& s)
    {
        out << "  Supplier: " << s.supplier_name
            << " | ID: " << s.supplier_id
            << " | Contact: " << s.contact_number;

        return out;
    }
};


// CLASS 9 : transaction log(Template Class)

template <typename t>
class transaction_log
{

private:

    string  log_name;
    string* log_array;    
    int     log_count;    
    int     log_capacity; 

    
    void grow_array()
    {
        int     new_capacity = log_capacity * 2;
        string* new_array = new string[new_capacity];

       
        for (int i = 0; i < log_count; i++)
            new_array[i] = log_array[i];

        delete[] log_array;
        log_array = new_array;
        log_capacity = new_capacity;
    }

public:

    // constructor

    transaction_log(string name)
    {
        log_name = name;
        log_count = 0;
        log_capacity = 10;
        log_array = new string[log_capacity];
    }

    // copy constructor  

    transaction_log(const transaction_log& other)
    {
        log_name = other.log_name;
        log_count = other.log_count;
        log_capacity = other.log_capacity;
        log_array = new string[log_capacity];
        for (int i = 0; i < log_count; i++)
        {
            log_array[i] = other.log_array[i];
        }

    }

    // destructor 

    ~transaction_log()
    {
        delete[] log_array;
        log_array = nullptr;
    }


    void record_action(string action, string item_info)

    {
        if (log_count >= log_capacity)
            grow_array();

        string entry = "  Action: " + action + " | Item: " + item_info;
        log_array[log_count] = entry;
        log_count++;


    }


    void print_audit_trail()
    {
        cout << "\n  ===== AUDIT LOG: " << log_name << " =====" << endl;
        if (log_count == 0)
        {
            cout << "  No records yet." << endl;
            return;
        }

        for (int i = 0; i < log_count; i++)

            cout << "  " << (i + 1) << ". " << log_array[i] << endl;
        cout << "  =====================================" << endl;

    }

    int get_log_count() const { return log_count; }
};




//  MODULE 5  -  Z bhai


class inventory_section
{

private:

    int      aisle_number;
    int      capacity;        
    string   section_name;

    product** product_list;   
    int       prod_count;     
    int       prod_capacity; 
    

    void grow_array()
    {
        int      new_capacity = prod_capacity * 2;
        product** new_array = new product * [new_capacity];

        for (int i = 0; i < prod_count; i++)
            new_array[i] = product_list[i];

        delete[] product_list;
        product_list = new_array;
        prod_capacity = new_capacity;
    }

public:

    // default constructor

    inventory_section()
    {
        aisle_number = 1;
        capacity = 100;
        section_name = "general";
        prod_count = 0;
        prod_capacity = 10;
        product_list = new product * [prod_capacity];
    }

    // parameterised constructor

    inventory_section(int aisle, int cap, string name)
    {
        aisle_number = aisle;
        capacity = cap;
        section_name = name;
        prod_count = 0;
        prod_capacity = 10;
        product_list = new product * [prod_capacity];
    }

    // copy constructor 

    inventory_section(const inventory_section& other)
    {
        aisle_number = other.aisle_number;
        capacity = other.capacity;
        section_name = other.section_name;
        prod_count = other.prod_count;
        prod_capacity = other.prod_capacity;
        product_list = new product * [prod_capacity];

        for (int i = 0; i < prod_count && i < prod_capacity; i++)
        {
            product_list[i] = other.product_list[i];
        }
    }


    inventory_section& operator=(const inventory_section& other)
    {
        if (this != &other)
        {
            delete[] product_list;

            aisle_number = other.aisle_number;
            capacity = other.capacity;
            section_name = other.section_name;
            prod_count = other.prod_count;
            prod_capacity = other.prod_capacity;
            product_list = new product * [prod_capacity];

            for (int i = 0; i < prod_count && i < prod_capacity; i++)
            {
                product_list[i] = other.product_list[i];
            }
        }

        return *this;
    }

    // destructor 

    ~inventory_section()
    {
        delete[] product_list;
        product_list = nullptr;
    }


    void set_aisle(int a)
    {
        aisle_number = a;
    }

    void set_capacity(int c)
    {
        capacity = c;
    }

    void set_name(string n)
    {
        section_name = n;
    }

    

    int    get_aisle()    const { return aisle_number; }

    int    get_capacity() const { return capacity; }

    string get_name()     const { return section_name; }

    int    get_count()    const { return prod_count; }

    

    bool add_stock(product* p)
    {
        if (prod_count >= capacity)
        {
            cout << "   Section '" << section_name << "' is full." << endl;
            return false;
        }
        if (prod_count >= prod_capacity)
            grow_array();

        product_list[prod_count] = p;
        prod_count++;
        return true;
    }

    

    void sort_by_id()
    {
        for (int i = 0; i < prod_count - 1; i++)
        {
            for (int j = 0; j < prod_count - i - 1; j++)
            {
                if (product_list[j]->get_product_id() > product_list[j + 1]->get_product_id())
                {
                    product* temp = product_list[j];
                    product_list[j] = product_list[j + 1];
                    product_list[j + 1] = temp;
                }
            }
        }

        cout << "   Section '" << section_name << "' sorted by product ID." << endl;
    }


    product* operator[](int index)
    {
        if (index >= 0 && index < prod_count)
            return product_list[index];
        cout << "   Index out of range in section '" << section_name << "'" << endl;
        return nullptr;
    }

    inventory_section operator+(const inventory_section& other)
    {
        inventory_section merged(aisle_number,
            capacity + other.capacity,
            section_name + "_merged_" + other.section_name);

        for (int i = 0; i < prod_count; i++)
            merged.add_stock(product_list[i]);
        for (int i = 0; i < other.prod_count; i++)
            merged.add_stock(other.product_list[i]);
        return merged;
    }

    void display_section()
    {
        cout << "\n  ===== SECTION: " << section_name
            << " (Aisle " << aisle_number << ") =====" << endl;
        cout << "  Capacity : " << capacity << " | Used : " << prod_count << endl;

        if (prod_count == 0)
        {
            cout << "  No products in this section." << endl;
            return;
        }

        for (int i = 0; i < prod_count; i++)
        {
            cout << "  [" << i << "] " << *product_list[i] << endl;
        }
    }


    bool has_product(int id)
    {
        for (int i = 0; i < prod_count; i++)
        {
            if (product_list[i]->get_product_id() == id)
            {
                return true;
            }
        }
        return false;
    }


    double get_section_value()
    {
        double total = 0;

        for (int i = 0; i < prod_count; i++)
            total += product_list[i]->calculate_value();
        return total;
    }
};


// CLASS 11 : warehouse


class warehouse
{

private:

    string location_id;
    double total_square_footage;

    inventory_section* sections;
    int   sec_count;
    int  sec_capacity;


    product** all_products;
    int       prod_count;
    int       prod_capacity;

   

    void grow_sections()
    {
        int       new_capacity = sec_capacity * 2;
        inventory_section* new_array = new inventory_section[new_capacity];

        for (int i = 0; i < sec_count; i++)
            new_array[i] = sections[i];

        delete[] sections;
        sections = new_array;
        sec_capacity = new_capacity;
    }


    void grow_products()
    {
        int      new_capacity = prod_capacity * 2;
        product** new_array = new product * [new_capacity];

        for (int i = 0; i < prod_count; i++)
            new_array[i] = all_products[i];

        delete[] all_products;
        all_products = new_array;
        prod_capacity = new_capacity;
    }

public:

    // default constructor

    warehouse()
    {
        location_id = "WH-001";
        total_square_footage = 50000.0;

        sec_count = 0;
        sec_capacity = 10;
        sections = new inventory_section[sec_capacity];

        prod_count = 0;
        prod_capacity = 50;
        all_products = new product * [prod_capacity];
    }

    // parameterised constructor

    warehouse(string loc, double sqft)
    {
        location_id = loc;
        total_square_footage = sqft;

        sec_count = 0;
        sec_capacity = 10;
        sections = new inventory_section[sec_capacity];

        prod_count = 0;
        prod_capacity = 50;
        all_products = new product * [prod_capacity];
    }

    // destructor 

    ~warehouse()
    {
        for (int i = 0; i < prod_count; i++)
        {
            delete all_products[i];
            all_products[i] = nullptr;
        }

        delete[] all_products;
        all_products = nullptr;

        delete[] sections;
        sections = nullptr;
    }

    void set_location(string l)
    {
        location_id = l;
    }

    void set_sqft(double s)
    {
        total_square_footage = s;
    }

    string get_location() const { return location_id; }

    double get_sqft()     const { return total_square_footage; }


    void add_section(inventory_section sec)
    {
        if (sec_count >= sec_capacity)
            grow_sections();
        sections[sec_count] = sec;
        sec_count++;
    }

    void add_product(product* p)
    {
        if (prod_count >= prod_capacity)
            grow_products();

        all_products[prod_count] = p;
        prod_count++;

        string type = p->get_product_type();
        bool   added_sec = false;

        for (int i = 0; i < sec_count; i++)
        {
            if (sections[i].get_name() == type)
            {
                sections[i].add_stock(p);
                added_sec = true;
                break;
            }
        }

        if (!added_sec)
        {
            for (int i = 0; i < sec_count; i++)
            {
                if (sections[i].get_name() == "general")
                {
                    sections[i].add_stock(p);
                    break;
                }
            }
        }
    }

    double get_global_value()
    {
        double total = 0;
        for (int i = 0; i < prod_count; i++)
            total += all_products[i]->calculate_value();
        return total;
    }


    void find_shortages(int threshold)
    {
        cout << "\n  ===== SHORTAGE REPORT (threshold: " << threshold << ") =====" << endl;
        bool found = false;

        for (int i = 0; i < prod_count; i++)
        {
            if (all_products[i]->get_quantity() < threshold)
            {
                cout << "   SHORTAGE: " << *all_products[i] << endl;
                found = true;
            }
        }

        if (!found)
            cout << "  No shortages found." << endl;
        cout << "  ====================================================" << endl;
    }

   

    void display_all_products()
    {
        cout << "\n  ===== WAREHOUSE: " << location_id << " =====" << endl;
        cout << "  Square Footage : " << total_square_footage << " sq ft" << endl;
        cout << "  Total Products : " << prod_count << endl;
        cout << "  Total Value    : Rs " << fixed << setprecision(2) << get_global_value() << endl;
        cout << "  -----------------------------------------" << endl;

        for (int i = 0; i < prod_count; i++)
        {
            all_products[i]->display_status();
            cout << endl;
        }
    }

    product* find_product(int id)
    {
        for (int i = 0; i < prod_count; i++)
        {
            if (all_products[i]->get_product_id() == id)
            {
                return all_products[i];
            }
        }

        return nullptr;
    }

    bool remove_product(int id)
    {
        for (int i = 0; i < prod_count; i++)
        {
            if (all_products[i]->get_product_id() == id)
            {
                delete all_products[i];
                all_products[i] = nullptr;

                for (int j = i; j < prod_count - 1; j++)
                    all_products[j] = all_products[j + 1];

                prod_count--;
                return true;
            }
        }
        return false;
    }


    void check_all_risks()
    {
        cout << "\n  ===== RISK ASSESSMENT REPORT =====" << endl;
        for (int i = 0; i < prod_count; i++)
        {
            double risk = all_products[i]->calculate_risk();
            cout << "  Product: " << all_products[i]->get_product_name()
                << " | Risk: " << risk;

            if (risk >= 7.0)
            {
                cout << "   HIGH RISK!" << endl;
            }
            else if (risk >= 3.0)
            {
                cout << "   Medium Risk" << endl;
            }
            else
            {
                cout << "   Low Risk" << endl;
            }
        }

        cout << "  ==================================" << endl;
    }

    void display_summary()
    {
        cout << "\n  ===== WAREHOUSE SUMMARY =====" << endl;
        cout << "  Location ID    : " << location_id << endl;
        cout << "  Square Footage : " << total_square_footage << " sq ft" << endl;
        cout << "  Total Sections : " << sec_count << endl;
        cout << "  Total Products : " << prod_count << endl;
        cout << "  Total Value    : Rs " << fixed << setprecision(2) << get_global_value() << endl;
        cout << "  =============================" << endl;
    }

    

    int       get_product_count() { return prod_count; }

    product** get_all_products() { return all_products; }
};


//  MODULE 6  -  Khurram sab


void save_all_products(warehouse& wh)
{
    ofstream file(product_file);

    if (!file.is_open())
    {
        cout << "   Could not open " << product_file << " for saving." << endl;
        return;
    }

    int       count = wh.get_product_count();

    product** all = wh.get_all_products();

    file << count << "\n";

    for (int i = 0; i < count; i++)
    {
        all[i]->save_to_file(file);
        file << "---\n";
    }

    file.close();

    cout << "   Products saved to " << product_file << endl;
}

void load_all_products(warehouse& wh, transaction_log<product>& plog)
{
    ifstream file(product_file);

    if (!file.is_open())
        return;   

    int count = 0;
    file >> count;

    file.ignore(1000, '\n');

    for (int i = 0; i < count; i++)
    {
        string type;
        getline(file, type);

        if (type == "electronic")
        {
            int id, qty, voltage, warranty;
            double price;
            string name, brand;

            file >> id;   file.ignore(1000, '\n');
            getline(file, name);

            file >> price >> qty >> voltage >> warranty;
            file.ignore(1000, '\n');

            getline(file, brand);
            string sep;   getline(file, sep);

            electronic_product* ep = new electronic_product(id, name, price, qty, voltage, warranty, brand);
            wh.add_product(ep);
            plog.record_action("loaded_from_file", name);
        }
        else if (type == "fragile_electronic")
        {
            int id, qty, voltage, warranty, frag;
            double price;

            string name, brand, pkg;

            file >> id;   file.ignore(1000, '\n');
            getline(file, name);

            file >> price >> qty >> voltage >> warranty;
            file.ignore(1000, '\n');
            getline(file, brand);

            file >> frag;   file.ignore(1000, '\n');
            getline(file, pkg);
            string sep;   getline(file, sep);

            fragile_electronics* fe = new fragile_electronics(id, name, price, qty, voltage, warranty, brand, frag, pkg);
            wh.add_product(fe);

            plog.record_action("loaded_from_file", name);
        }
        else if (type == "grocery")
        {
            int id, qty, cal, halal;
            double price;
            string name;

            file >> id;   file.ignore(1000, '\n');
            getline(file, name);

            file >> price >> qty >> cal >> halal;
            string sep;   getline(file, sep);   getline(file, sep);

            grocery_product* gp = new grocery_product(id, name, price, qty, cal, (bool)halal);
            wh.add_product(gp);

            plog.record_action("loaded_from_file", name);

        }

        else if (type == "perishable_grocery")
        {
            int id, qty, cal, halal;
            double price, temp;
            string name, expiry;

            file >> id;   file.ignore(1000, '\n');
            getline(file, name);

            file >> price >> qty >> cal >> halal;
            file.ignore(1000, '\n');

            getline(file, expiry);

            file >> temp;
            string sep;   getline(file, sep);   getline(file, sep);

            perishable_grocery* pg = new perishable_grocery(id, name, price, qty, cal, (bool)halal, expiry, temp);
            wh.add_product(pg);

            plog.record_action("loaded_from_file", name);
        }

        else if (type == "non_perishable")
        {
            int id, qty, cal, halal, shelf;
            double price;
            string name, pres;

            file >> id;   file.ignore(1000, '\n');
            getline(file, name);

            file >> price >> qty >> cal >> halal >> shelf;
            file.ignore(1000, '\n');

            getline(file, pres);

            string sep;   getline(file, sep);

            non_perishable* np = new non_perishable(id, name, price, qty, cal, (bool)halal, shelf, pres);
            wh.add_product(np);

            plog.record_action("loaded_from_file", name);
        }

        else if (type == "clothing")
        {
            int id, qty;
            double price;
            string name, sz, fab, gen;

            file >> id;   file.ignore(1000, '\n');
            getline(file, name);

            file >> price >> qty;
            file.ignore(1000, '\n');

            getline(file, sz);
            getline(file, fab);
            getline(file, gen);

            string sep;   getline(file, sep);

            clothing_product* cp = new clothing_product(id, name, price, qty, sz, fab, gen);

            wh.add_product(cp);

            plog.record_action("loaded_from_file", name);
        }

        else
        {
            string sep;   getline(file, sep);
        }
    }

    file.close();
    cout << "   Loaded " << count << " products from " << product_file << endl;
}

void register_user()
{
    clear_screen();
    cout << "\n  ===== CREATE ACCOUNT =====" << endl;
    cout << "  Username rules : letters, digits, underscores only" << endl;
    cout << "  Password rules : at least 6 characters, at least 1 digit" << endl;
    cout << "  -------------------------" << endl;

    string username;
    while (true)
    {
        username = get_string_input("  Enter new username : ");

        if (!is_valid_username(username))
        {
            cout << "   Invalid username. Use only letters, digits, or underscores." << endl;
            continue;
        }

        bool taken = false;
        ifstream check(user_file);

        if (check.is_open())
        {
            string u, p;
            while (getline(check, u) && getline(check, p))
            {
                if (u == username)
                {
                    taken = true;
                    break;
                }
            }
            check.close();
        }

        if (taken)
        {
            cout << "   Username '" << username << "' is already taken. Try a different one." << endl;
            continue;
        }

        break;
    }

    string password;

    while (true)
    {
        password = get_string_input("  Enter new password : ");

        if (!is_valid_password(password))
        {
            cout << "   Weak password. Must be at least 6 characters and contain at least 1 digit." << endl;
            continue;
        }

        string confirm = get_string_input("  Confirm password   : ");

        if (confirm != password)
        {
            cout << "   Passwords do not match. Try again." << endl;
            continue;
        }

        break;
    }

    ofstream ufile(user_file, ios::app);

    if (ufile.is_open())
    {
        ufile << username << "\n" << password << "\n";
        ufile.close();
        cout << "\n   Account created successfully! You can now login." << endl;
    }

    else
        cout << "   Error: Could not save account." << endl;

    cout << "\n  Press Enter to continue...";
    cin.get();
}

bool login_user(string& logged_username)
{
    clear_screen();

    cout << "\n  ===== LOGIN =====" << endl;

    string username = get_string_input("  Username : ");
    string password = get_string_input("  Password : ");

    ifstream ufile(user_file);

    if (!ufile.is_open())
    {
        cout << "   No accounts found. Please register first." << endl;
        cout << "\n  Press Enter to continue...";
        cin.get();
        return false;
    }

    string u, p;

    while (getline(ufile, u) && getline(ufile, p))
    {
        if (u == username && p == password)
        {
            ufile.close();

            logged_username = username;
            cout << "\n   Login successful! Welcome, " << username << "!" << endl;
            cout << "\n  Press Enter to continue...";
            cin.get();

            return true;
        }
    }

    ufile.close();

    cout << "\n   Incorrect username or password." << endl;
    cout << "\n  Press Enter to continue...";
    cin.get();

    return false;
}


void add_electronic(warehouse& wh, transaction_log<product>& plog)
{
    clear_screen();
    cout << "\n  --- Add Electronic Product ---" << endl;

    int id = get_int_input("  Product ID      : ", 1, 999999);

    string name = get_string_input("  Product Name    : ");
    double price = get_double_input("  Price (Rs)      : ", 0.0, 10000000.0);

    int qty = get_int_input("  Quantity        : ", 0, 100000);
    int voltage = get_int_input("  Voltage (V)     : ", 1, 10000);
    int warranty = get_int_input("  Warranty (mo)   : ", 0, 600);

    string brand = get_string_input("  Brand Name      : ");

    electronic_product* ep = new electronic_product(id, name, price, qty, voltage, warranty, brand);
    wh.add_product(ep);

    plog.record_action("added_electronic", name);
    save_all_products(wh);

    cout << "\n   Electronic product added and saved." << endl;
    cout << "\n  Press Enter to continue...";
    cin.get();
}

void add_fragile_electronic(warehouse& wh, transaction_log<product>& plog)
{
    clear_screen();
    cout << "\n  --- Add Fragile Electronic Product ---" << endl;

    int id = get_int_input("  Product ID        : ", 1, 999999);

    string name = get_string_input("  Product Name      : ");
    double price = get_double_input("  Price (Rs)        : ", 0.0, 10000000.0);
    int qty = get_int_input("  Quantity          : ", 0, 100000);

    int voltage = get_int_input("  Voltage (V)       : ", 1, 10000);
    int warranty = get_int_input("  Warranty (mo)     : ", 0, 600);
    string brand = get_string_input("  Brand Name        : ");

    int frag = get_int_input("  Fragility (1-10)  : ", 1, 10);
    string pkg = get_string_input("  Packaging Type    : ");

    fragile_electronics* fe = new fragile_electronics(id, name, price, qty, voltage, warranty, brand, frag, pkg);
    wh.add_product(fe);

    plog.record_action("added_fragile_electronic", name);
    save_all_products(wh);

    cout << "\n   Fragile electronic added and saved." << endl;
    cout << "\n  Press Enter to continue...";

    cin.get();
}

void add_perishable_grocery(warehouse& wh, transaction_log<product>& plog)
{
    clear_screen();

    cout << "\n  --- Add Perishable Grocery ---" << endl;

    int id = get_int_input("  Product ID              : ", 1, 999999);
    string name = get_string_input("  Product Name            : ");

    double price = get_double_input("  Price (Rs)              : ", 0.0, 10000000.0);
    int qty = get_int_input("  Quantity                : ", 0, 100000);

    int cal = get_int_input("  Calories per serving    : ", 0, 10000);

    int halal_choice = get_int_input("  Halal? (1=Yes, 0=No)    : ", 0, 1);
    string expiry = get_string_input("  Expiry Date (YYYY-MM-DD): ");

    double temp = get_double_input("  Storage Temp (Celsius)  : ", -50.0, 100.0);

    perishable_grocery* pg = new perishable_grocery(id, name, price, qty, cal, (bool)halal_choice, expiry, temp);
    wh.add_product(pg);

    plog.record_action("added_perishable_grocery", name);
    save_all_products(wh);

    cout << "\n   Perishable grocery added and saved." << endl;

    cout << "\n  Press Enter to continue...";

    cin.get();
}

void add_non_perishable(warehouse& wh, transaction_log<product>& plog)
{
    clear_screen();

    cout << "\n  --- Add Non-Perishable Grocery ---" << endl;

    int id = get_int_input("  Product ID                           : ", 1, 999999);
    string name = get_string_input("  Product Name                         : ");

    double price = get_double_input("  Price (Rs)                           : ", 0.0, 10000000.0);

    int qty = get_int_input("  Quantity                             : ", 0, 100000);
    int cal = get_int_input("  Calories per serving                 : ", 0, 10000);

    int halal_choice = get_int_input("  Halal? (1=Yes, 0=No)                 : ", 0, 1);

    int shelf = get_int_input("  Shelf Life (years)                   : ", 1, 100);

    string pres = get_string_input("  Preservative Level (low/medium/high) : ");

    non_perishable* np = new non_perishable(id, name, price, qty, cal, (bool)halal_choice, shelf, pres);
    wh.add_product(np);

    plog.record_action("added_non_perishable", name);

    save_all_products(wh);

    cout << "\n   Non-perishable added and saved." << endl;

    cout << "\n  Press Enter to continue...";

    cin.get();

}

void add_clothing(warehouse& wh, transaction_log<product>& plog)
{
    clear_screen();

    cout << "\n  --- Add Clothing Product ---" << endl;

    int id = get_int_input("  Product ID                     : ", 1, 999999);
    string name = get_string_input("  Product Name                   : ");
    double price = get_double_input("  Price (Rs)                     : ", 0.0, 10000000.0);

    int qty = get_int_input("  Quantity                       : ", 0, 100000);
    string sz = get_string_input("  Size (S/M/L/XL/XXL)            : ");

    string fab = get_string_input("  Fabric (cotton/polyester/etc)  : ");

    string gen = get_string_input("  Gender (male/female/unisex)    : ");

    clothing_product* cp = new clothing_product(id, name, price, qty, sz, fab, gen);
    wh.add_product(cp);

    plog.record_action("added_clothing", name);

    save_all_products(wh);

    cout << "\n   Clothing product added and saved." << endl;

    cout << "\n  Press Enter to continue...";

    cin.get();
}

void show_main_menu(warehouse& wh,
    transaction_log<product>& plog,
    transaction_log<supplier>& slog,
    string& username)
{
    int choice;
    do
    {
        clear_screen();

        cout << "\n  ==========================================" << endl;
        cout << "    INVENTORY MANAGEMENT SYSTEM" << endl;
        cout << "    Logged in as: " << username << endl;
        cout << "  ==========================================" << endl;
        cout << "   1. Add Product" << endl;
        cout << "   2. View All Products" << endl;
        cout << "   3. Search Product by ID" << endl;
        cout << "   4. Delete Product by ID" << endl;
        cout << "   5. Apply Discount to Product" << endl;
        cout << "   6. Check All Risks" << endl;
        cout << "   7. Find Shortages" << endl;
        cout << "   8. Warehouse Summary" << endl;
        cout << "   9. View Audit Log" << endl;
        cout << "  10. Supplier Invoice Generator" << endl;
        cout << "   0. Logout" << endl;
        cout << "  ==========================================" << endl;

        choice = get_int_input("  Enter choice: ", 0, 10);

        if (choice == 1)
        {
            clear_screen();
            cout << "\n  Select Product Type:" << endl;
            cout << "  1. Electronic" << endl;
            cout << "  2. Fragile Electronic" << endl;
            cout << "  3. Perishable Grocery" << endl;
            cout << "  4. Non-Perishable Grocery" << endl;
            cout << "  5. Clothing" << endl;

            int p_type = get_int_input("  Type: ", 1, 5);

            if (p_type == 1)
            {
                add_electronic(wh, plog);
            }

            else if (p_type == 2)
            {
                add_fragile_electronic(wh, plog);
            }

            else if (p_type == 3)
            {
                add_perishable_grocery(wh, plog);
            }

            else if (p_type == 4)
            {
                add_non_perishable(wh, plog);
            }

            else if (p_type == 5)
            {
                add_clothing(wh, plog);
            }

        }

        else if (choice == 2)
        {
            clear_screen();

            if (wh.get_product_count() == 0)
            {
                cout << "  No products in warehouse." << endl;
            }
            else
                wh.display_all_products();
            cout << "\n  Press Enter to continue...";
            cin.get();
        }

        else if (choice == 3)
        {
            clear_screen();
            int id = get_int_input("  Enter Product ID to search: ", 1, 999999);

            product* found = wh.find_product(id);

            if (found)
            {
                cout << "\n  Product found:" << endl;
                found->display_status();

                plog.record_action("searched", found->get_product_name());
            }
            else
                cout << "   Product with ID " << id << " not found." << endl;

            cout << "\n  Press Enter to continue...";
            cin.get();
        }

        else if (choice == 4)
        {
            clear_screen();

            int id = get_int_input("  Enter Product ID to delete: ", 1, 999999);
            product* found = wh.find_product(id);

            string p_name = (found ? found->get_product_name() : "unknown");

            if (wh.remove_product(id))
            {
                cout << "   Product deleted." << endl;
                plog.record_action("deleted", p_name);
                save_all_products(wh);
            }
            else
                cout << "   Product not found." << endl;

            cout << "\n  Press Enter to continue...";

            cin.get();
        }

        else if (choice == 5)
        {
            clear_screen();
            int id = get_int_input("  Enter Product ID: ", 1, 999999);

            product* found = wh.find_product(id);

            if (found)
            {
                double disc = get_double_input("  Enter discount %: ", 0.0, 100.0);
                found->apply_discount(disc);

                plog.record_action("discount_applied", found->get_product_name());
                save_all_products(wh);
            }

            else
                cout << "   Product not found." << endl;

            cout << "\n  Press Enter to continue...";

            cin.get();
        }

        else if (choice == 6)
        {
            clear_screen();
            wh.check_all_risks();
            cout << "\n  Press Enter to continue...";
            cin.get();
        }

        else if (choice == 7)
        {
            clear_screen();
            int threshold = get_int_input("  Enter minimum quantity threshold: ", 0, 100000);
            wh.find_shortages(threshold);
            cout << "\n  Press Enter to continue...";
            cin.get();
        }


        else if (choice == 8)
        {
            clear_screen();
            wh.display_summary();
            cout << "\n  Press Enter to continue...";
            cin.get();
        }

        else if (choice == 9)
        {
            clear_screen();
            plog.print_audit_trail();
            slog.print_audit_trail();
            cout << "\n  Press Enter to continue...";
            cin.get();
        }

        else if (choice == 10)
        {
            clear_screen();
            cout << "\n  --- Supplier Invoice Generator ---" << endl;

            int    sid = get_int_input("  Supplier ID    : ", 1, 999999);
            string s_name = get_string_input("  Supplier Name  : ");

            string terms = get_string_input("  Contract Terms : ");
            string contact = get_string_input("  Contact Number : ");

            double disc = get_double_input("  Discount %     : ", 0.0, 100.0);

            supplier s(sid, s_name, terms, contact, disc);

            string prod_name = get_string_input("  Product Name   : ");
            int    qty = get_int_input("  Quantity       : ", 1, 100000);

            double unit_price = get_double_input("  Unit Price     : ", 0.0, 10000000.0);

            s.generate_invoice(prod_name, qty, unit_price);

            slog.record_action("invoice_generated", s_name + "_for_" + prod_name);

            cout << "\n  Press Enter to continue...";

            cin.get();
        }

    } while (choice != 0);

    cout << "   Logged out successfully." << endl;

}
int main()
{

    cout << "\n  ============================================" << endl;
    cout << "   ENTERPRISE INVENTORY MANAGEMENT SYSTEM" << endl;
    cout << "   OOP Lab Project | Semester 2" << endl;
    cout << "  ============================================" << endl;

    warehouse main_warehouse("WH-LAHORE-001", 75000.0);

    main_warehouse.add_section(inventory_section(1, 200, "electronic"));

    main_warehouse.add_section(inventory_section(2, 200, "fragile_electronic"));

    main_warehouse.add_section(inventory_section(3, 300, "grocery"));

    main_warehouse.add_section(inventory_section(4, 300, "perishable_grocery"));

    main_warehouse.add_section(inventory_section(5, 300, "non_perishable"));

    main_warehouse.add_section(inventory_section(6, 400, "clothing"));

    main_warehouse.add_section(inventory_section(7, 500, "general"));


    transaction_log<product>  product_log("product_transaction_log");

    transaction_log<supplier> supplier_log("supplier_transaction_log");


    cout << "\n  Loading existing inventory from file..." << endl;

    load_all_products(main_warehouse, product_log);
    bool running = true;

    while (running)
    {
        clear_screen();

        cout << "\n  ===== WELCOME =====" << endl;
        cout << "  1. Login" << endl;
        cout << "  2. Register" << endl;
        cout << "  0. Exit" << endl;

        int start_choice = get_int_input("  Enter choice: ", 0, 2);

        if (start_choice == 1)
        {
            string logged_user;

            if (login_user(logged_user))
            {

                product_log.record_action("login", logged_user);
                show_main_menu(main_warehouse, product_log, supplier_log, logged_user);

            }
        }

        else if (start_choice == 2)
        {
            register_user();
        }

        else if (start_choice == 0)

        {
            cout << "\n  Saving data and exiting..." << endl;
            save_all_products(main_warehouse);
            cout << "  Goodbye!" << endl;
            running = false;
        }
    }

    return 0;
}