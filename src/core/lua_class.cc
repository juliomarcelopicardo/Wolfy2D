/** Copyright Julio Marcelo Picardo. SouthBros 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*
*/

#include "core/lua_class.h"
#include "core/core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>


namespace W2D {
/****************************************
***     CONSTRUCTORS & DESTRUCTOR     ***
****************************************/
Lua::Lua() {
  printf("Initializing Lua...\n");
  L_ = luaL_newstate();
  luaL_openlibs(L_);
}

Lua::~Lua() {
  printf("Closing Lua...\n");
  lua_close(L_);
}

lua_State* Lua::operator*() {
  return L_;
}

void Lua::resetLua() {
  lua_close(L_);
  L_ = luaL_newstate();
  luaL_openlibs(L_);
}



/****************************************
***            LUA METHODS            ***
****************************************/

// UTILS
void Lua::doFile(const char* lua_file) {
  if (luaL_dofile(L_, lua_file)) {
    std::string tmp("Oops! Something went wrong with the Lua file, error: ");
    tmp += lua_tostring(L_, -1);
    printf("\n %s",tmp.c_str());
    lua_pop(L_, 1);
    exit(EXIT_FAILURE);
  }
  else {
    printf("Lua file %s loaded!\n", lua_file);
  }
}

void Lua::registerFunction(const char* label_to_lua, lua_CFunction function) {
  lua_register(L_, label_to_lua, function);
}



void Lua::call(const uint32 input_param, const uint32 output_param) {
  lua_call(L_, input_param, output_param);
}

int32 Lua::pcall(const uint32 input_param, const uint32 output_param,
                 const uint32 error) {
  if (lua_pcall(L_, input_param, output_param, error)) {
    std::string tmp("Oops! This went wrong calling the function: ");
    tmp += lua_tostring(L_, -1);
    printf("\n %s", tmp.c_str());
    lua_pop(L_, 1);
    return 1;
  }
  else {
    return 0;
  }
}

int32 Lua::getTop() {
  return lua_gettop(L_);
}



// STACK MODIFIERS
int32 Lua::checkStack(const uint32 space_to_check_in_stack) {
  return lua_checkstack(L_, space_to_check_in_stack);
}

void Lua::getGlobal(const char* lua_data) {
  lua_getglobal(L_, lua_data);
  /* Retornos de getglobal.
      - 0 - Archivo inexistente o nill.
      - 1 - Boolean.
      - 2 - Userdata.
      - 3 - Numero.
      - 4 - String.
      - 5 - Tabla.
      - 6 - Funcion.
  */
}

int32 Lua::getGlobalIntegerAndPop(const char* lua_data) {
  lua_getglobal(L_, lua_data);
  int32 tmp_int = 0;
  if (lua_isinteger(L_, -1)) {
    tmp_int = (int32)lua_tointeger(L_, -1);
  }
  else if (lua_isnumber(L_, -1)) {
    tmp_int = (int32)lua_tonumber(L_, -1);
  }
  else {
    tmp_int = -99999;
  }
  lua_pop(L_, 1);
  return tmp_int;
}

float Lua::getGlobalNumberAndPop(const char* lua_data) {
  lua_getglobal(L_, lua_data);
  float tmp_float = 0;
  if (lua_isnumber(L_, -1)) {
    tmp_float = (float)lua_tonumber(L_, -1);
  }
  else if (lua_isinteger(L_, -1)) {
    tmp_float = (float)lua_tointeger(L_, -1);
  }
  else {
    tmp_float = -99999.9f;
  }
  lua_pop(L_, 1);
  return tmp_float;
}

float Lua::getGlobalBooleanAndPop(const char* lua_data) {
  lua_getglobal(L_, lua_data);
  bool tmp_bool = lua_isboolean(L_, -1) && lua_toboolean(L_, -1);
  lua_pop(L_, 1);
  return tmp_bool;
}

void Lua::getField(const int32 position_in_stack, const char* field_name) {
  if (lua_istable(L_, position_in_stack)) {
    lua_getfield(L_, position_in_stack, field_name);
  }
  else {
    printf("The selected stack position wasn't a table!\n");
  }
}



void Lua::pop(const int32 num_to_delete) {
  lua_pop(L_, num_to_delete);
}

void Lua::resetStack() {
  lua_pop(L_, -1);
}

void Lua::removeElement(const int32 position_in_stack) {
  lua_remove(L_, position_in_stack);
}



// STACK MANUAL PUSHERS
void Lua::pushInteger(const int32 integer) {
  lua_pushinteger(L_, integer);
}

void Lua::pushNumber(const float number) {
  lua_pushnumber(L_, number);
}

void Lua::pushBoolean(const bool boolean) {
  lua_pushboolean(L_, boolean);
}

void Lua::pushString(const char* string) {
  lua_pushstring(L_, string);
}

void Lua::pushLiteral(const char* string) {
  lua_pushlstring(L_, string, strlen(string));
}

void Lua::pushNil() {
  lua_pushnil(L_);
}



// GETTERS FROM THE STACK
int32 Lua::toInteger(const int32 position_in_stack) {
  if (lua_isinteger(L_, position_in_stack)) {
    return (int32)lua_tointeger(L_, position_in_stack);
  }
  else {
    return -99999;
  }
}

float Lua::toNumber(const int32 position_in_stack) {
  if (lua_isnumber(L_, position_in_stack)) {
    return (float)lua_tonumber(L_, position_in_stack);
  }
  else {
    return -99999.9f;
  }
}

bool Lua::toBoolean(const int32 position_in_stack) {
  return lua_isboolean(L_, position_in_stack) && lua_toboolean(L_, position_in_stack);
}

bool Lua::toNil(const int32 position_in_stack) {
  if (lua_isnil(L_, position_in_stack)) {
    return true;
  }
  else {
    return false;
  }
}

char* Lua::toString(const int32 position_in_stack) {
  if (lua_isstring(L_, position_in_stack)) {
    return (char*) lua_tostring(L_, position_in_stack);
  }
  else {
    return "It wasn't a string.\n";
  }
}



// IS TYPE COMPARE
bool Lua::isInteger(const int32 position_in_stack) {
  if (lua_isinteger(L_, position_in_stack)) {
    return true;
  }
  else {
    return false;
  }
}

bool Lua::isNumber(const int32 position_in_stack) {
  if (lua_isnumber(L_, position_in_stack)) {
    return true;
  }
  else {
    return false;
  }
}

bool Lua::isBoolean(const int32 position_in_stack) {
  if (lua_isboolean(L_, position_in_stack)) {
    return true;
  }
  else {
    return false;
  }
}

bool Lua::isString(const int32 position_in_stack) {
  if (lua_isstring(L_, position_in_stack)) {
    return true;
  }
  else {
    return false;
  }
}

bool Lua::isNil(const int32 position_in_stack) {
  if (lua_isnil(L_, position_in_stack)) {
    return true;
  }
  else {
    return false;
  }
}

bool Lua::isTable(const int32 position_in_stack) {
  if (lua_istable(L_, position_in_stack)) {
    return true;
  }
  else {
    return false;
  }
}

bool Lua::isFunction(const int32 position_in_stack) {
  if (lua_isfunction(L_, position_in_stack)) {
    return true;
  }
  else {
    return false;
  }
}

bool Lua::isCFunction(const int32 position_in_stack) {
  if (lua_iscfunction(L_, position_in_stack)) {
    return true;
  }
  else {
    return false;
  }
}



/****************************************
***          CUSTOM METHODS           ***
****************************************/
int32 Lua::getIntegerFromTable(const char* table, const char* field) {
  lua_getglobal(L_, table);
  lua_getfield(L_, -1, field);
  int32 tmp_int = 0;
  if (lua_isinteger(L_, -1)) {
    tmp_int = (int32)lua_tointeger(L_, -1);
  }
  else if (lua_isnumber(L_, -1)) {
    tmp_int = (int32)lua_tonumber(L_, -1);
  }
  else {
    tmp_int = -99999;
  }
  lua_pop(L_, 2);
  return tmp_int;
}

float Lua::getNumberFromTable(const char* table, const char* field) {
  lua_getglobal(L_, table);
  lua_getfield(L_, -1, field);
  float tmp_float = 0.0f;
  if (lua_isnumber(L_, -1)) {
    tmp_float = (float)lua_tonumber(L_, -1);
  }
  else if (lua_isinteger(L_, -1)) {
    tmp_float = (float)lua_tointeger(L_, -1);
  }
  else {
    tmp_float = -99999.9f;
  }
  lua_pop(L_, 2);
  return tmp_float;
}

bool Lua::getBooleanFromTable(const char* table, const char* field) {
  lua_getglobal(L_, table);
  lua_getfield(L_, -1, field);
  bool tmp_bool = lua_isboolean(L_, -1) && lua_toboolean(L_, -1);
  lua_pop(L_, 2);
  return tmp_bool;
}

char* Lua::getStringFromTable(const char* table, const char* field) {
  lua_getglobal(L_, table);
  lua_getfield(L_, -1, field);
  if (lua_isstring(L_, -1)) {
    char* tmp_string = (char*) lua_tostring(L_, -1);
    lua_pop(L_, 2);
    return tmp_string;
  }
  lua_pop(L_, 2);
  return "It wasn't a string.\n";
}

int32 Lua::getIntegerFromArray(const char* table, const uint32 index) {
  lua_getglobal(L_, table);
  //index + 1 ya que el array en Lua empieza desde 1:
  lua_pushnumber(L_, index + 1);
  lua_gettable(L_, -2);
  int32 tmp_int = 0;
  if (lua_isinteger(L_, -1)) {
    tmp_int = (int32)lua_tointeger(L_, -1);
  }
  else if (lua_isnumber(L_, -1)) {
    tmp_int = (int32)lua_tonumber(L_, -1);
  }
  else {
    tmp_int = -99999;
  }
  lua_pop(L_, 2);
  return tmp_int;
}

double Lua::getNumberFromArray(const char* table, const uint32 index) {
  lua_getglobal(L_, table);
  //index + 1 ya que el array en Lua empieza desde 1:
  lua_pushnumber(L_, index + 1);
  lua_gettable(L_, -2);
  float tmp_float = 0.0f;
  if (lua_isnumber(L_, -1)) {
    tmp_float = (float)lua_tonumber(L_, -1);
  }
  else if (lua_isinteger(L_, -1)) {
    tmp_float = (float)lua_tointeger(L_, -1);
  }
  else {
    tmp_float = -99999.9f;
  }
  lua_pop(L_, 2);
  return tmp_float;
}

char* Lua::getStringFromArray(const char* table, const uint32 index) {
  lua_getglobal(L_, table);
  //index + 1 ya que el array en Lua empieza desde 1:
  lua_pushnumber(L_, index + 1);
  lua_gettable(L_, -2);
  if (lua_isstring(L_, -1)) {
    char* tmp_string = (char*)lua_tostring(L_, -1);
    lua_pop(L_, 2);
    return tmp_string;
  }
  lua_pop(L_, 2);
  return "It wasn't a string.\n";
}

bool Lua::getBooleanFromArray(const char* table, const uint32 index) {
  lua_getglobal(L_, table);
  //index + 1 ya que el array en Lua empieza desde 1:
  lua_pushnumber(L_, index + 1); 
  lua_gettable(L_, -2);
  bool tmp_bool = lua_isboolean(L_, -1) && lua_toboolean(L_, -1);
  lua_pop(L_, 2);
  return tmp_bool;
}

}; /* W2D */