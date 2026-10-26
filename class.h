#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
  extern  const string product_file;
extern const  string user_file;

 class product;
 class electronic_product;
 class fragile_electronics; 

  class grocery_product;
 class perishable_grocery;
 class non_perishable;
class clothing_product;
class supplier;
class inventory_section;

class warehouse;
 template <typename T> class transaction_log;


void  clear_screen();
string get_string_input(string prompt);
int  get_int_input(string prompt, int min_val, int max_val);
double get_double_input(string prompt, double min_val, double max_val);
bool is_valid_username(string s);
bool  is_valid_password(string s);
void save_all_products(warehouse& wh);
void   load_all_products(warehouse& wh, transaction_log<product>& plog);
void  register_user();
bool   login_user(string& logged_username);
void  add_electronic(warehouse& wh, transaction_log<product>& plog);
void add_fragile_electronic(warehouse& wh, transaction_log<product>& plog);
void  add_perishable_grocery(warehouse& wh, transaction_log<product>& plog);
void add_non_perishable(warehouse& wh, transaction_log<product>& plog);
void add_clothing(warehouse& wh, transaction_log<product>& plog);
void  show_main_menu(warehouse& wh, transaction_log<product>& plog,
    transaction_log<supplier>& slog, string& username);

#endif#
