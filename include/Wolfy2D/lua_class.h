/** Copyright Julio Marcelo Picardo 2017-18, all rights reserved.
*
*  @project Wolfy2D
*  @author Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
*/

#ifndef __LUA_CLASS__
#define __LUA_CLASS__ 1

#include "Wolfy2D.h"

namespace W2D {

class Lua {
 public:
  /****************************************
  ***     CONSTRUCTORS & DESTRUCTOR     ***
  ****************************************/

  /// Initializes Lua (creates new state and opens libraries).
  Lua();

  /// Closes Lua.
  ~Lua();

  struct lua_State* operator*();

  /// Closes and reinitializes Lua.
  void resetLua();



  /****************************************
  ***            LUA METHODS            ***
  ****************************************/

  // UTILS

  /** @brief Opens a Lua configuration file.
    *
    *  @param Lua_file: path to the file.
    *
    */
  void doFile(const char* lua_file);

  /** @brief Registers a function in the Lua stack.
    *
    *  @param Label_to_lua: identifier of the function in the stack.
    *  @param Function: function to register.
    *
    */
  void registerFunction(const char* label_to_lua, lua_CFunction function);


  /** @brief Calls a Lua function.
    *
    *  Lua function called was previously loaded in the stack with
    *  'getGlobal' method.
    *
    *  @param Input_param: number of inputs loaded previously in the stack.
    *  @param Output_param: number of outputs loaded in the stack when the Lua
    *                       function finishes.
    *
    */
  void call(const uint32 input_param, const uint32 output_param);

  /** @brief Calls a Lua function in secure mode.
    *
    *  Lua function called was previously loaded in the stack with
    *  'getGlobal' method.
    *
    *  @param Input_param: number of inputs loaded previously in the stack.
    *  @param Output_param: number of outputs loaded in the stack when the Lua
    *                       function finishes.
    *  @param Error: '0' by default.
    *
    */
  int32 pcall(const uint32 input_param, const uint32 output_param, 
              const uint32 error = 0);

  /** @brief Returns the number of positions in the stack.
    *
    *  @return Returns the occupied positions in the stack.
    *
    */
  int32 getTop();



  // STACK MODIFIERS

  /** @brief Method which checks if the stack can be filled with 'x' data.
    *
    *  @param Space_to_check_in_stack: the number of positions to check if can
    *                                  be filled.
    *  @return If returns 1 or true, user can fill that number of positions
    *          because the stack has enough space.
    *
    */
  int32 checkStack(const uint32 space_to_check_in_stack);

  /** @brief Method used to load in the stack a global data of the
    *         Lua config. file: table, function...
    *
    *  @param Lua_data: name of the data to load.
    *
    */
  void getGlobal(const char* lua_data);

  /** @brief Method used to load a Lua global integer, remove it from the stack
    *         and return it.
    *
    *  @param Lua_data: name of the integer to load.
    *  @return Returns the integer if the data was that; '-99999' if not.
    *
    */
  int32 getGlobalIntegerAndPop(const char* lua_data);

  /** @brief Method used to load a Lua global float, remove it from the stack
    *         and return it.
    *
    *  @param Lua_data: name of the float to load.
    *  @return Returns the float if the data was that; '-99999.9' if not.
    *
    */
  float getGlobalNumberAndPop(const char* lua_data);

  /** @brief Method used to load a Lua global boolean, remove it from the stack
    *         and return it.
    *
    *  @param Lua_data: name of the boolean to load.
    *  @return Returns the boolean if the data was a boolean; 'false' if not.
    *
    */
  float getGlobalBooleanAndPop(const char* lua_data);

  /** @brief Method used to set in the stack one data of any Lua table.
    *
    *  @param Position_in_stack: position of the table in the stack.
    *  @param Field_name: table data name.
    *
    */
  void getField(const int32 position_in_stack, const char* field_name);

  /** @brief Method used to remove 'x' positions in the stack.
    *
    *  LIFO method.
    *
    *  @param Num_to_delete: number of elements to delete.
    *
    */
  void pop(const int32 num_to_delete);

  /** @brief Resets the Lua stack.
    *
    */
  void resetStack();

  /** @brief Method used to remove a concret position in the stack.
    *
    *  @param Position_in_stack: current position of the data in the stack.
    *
    */
  void removeElement(const int32 position_in_stack);



  // STACK MANUAL PUSHERS

  /** @brief Pushes an integer on top of the stack.
    *
    *  @param Integer: the data to push.
    *
    */
  void pushInteger(const int32 integer);

  /** @brief Pushes a float on top of the stack.
    *
    *  @param Number: the data to push.
    *
    */
  void pushNumber(const float number);

  /** @brief Pushes a boolean on top of the stack.
    *
    *  @param Boolean: the data to push.
    *
    */
  void pushBoolean(const bool boolean);

  /** @brief Pushes a string on top of the stack.
    *
    *  The difference between a string and a literal is that string has
    *  '\0' at the end.
    *
    *  @param String: the data to push.
    *
    */
  void pushString(const char* string);

  /** @brief Pushes a string on top of the stack.
    *
    *  The difference between a string and a literal is that string has
    *  '\0' at the end.
    *
    *  @param String: the data to push.
    *
    */
  void pushLiteral(const char* string);

  /** @brief Pushes a 'null' value on top of the stack.
    *
    */
  void pushNil();



  // GETTERS FROM THE STACK

  /** @brief Returns an integer from the stack.
    *
    *  @param Position_in_stack: the data current position in the stack.
    *  @param Returns the selected integer. If the data wasn't an integer,
    *         returns '-99999'.
    *
    */
  int32 toInteger(const int32 position_in_stack);

  /** @brief Returns a float from the stack.
    *
    *  @param Position_in_stack: the data current position in the stack.
    *  @param Returns the selected float. If the data wasn't a float,
    *         returns '-99999.9'.
    *
    */
  float toNumber(const int32 position_in_stack);

  /** @brief Returns a boolean from the stack.
    *
    *  @param Position_in_stack: the data current position in the stack.
    *  @param Returns the selected boolean. If the data wasn't a boolean,
    *         returns 'false'.
    *
    */
  bool toBoolean(const int32 position_in_stack);

  /** @brief Returns a boolean from the stack: 'true' if the selected position
    *         contained a 'null' value; 'false' if not.
    *
    *  @param Position_in_stack: the data current position in the stack.
    *  @param Returns 'true' if the selected position contained a 'null'
    *         value; 'false' if not.
    *
    */
  bool toNil(const int32 position_in_stack);

  /** @brief Returns a string from the stack.
    *
    *  @param Position_in_stack: the data current position in the stack.
    *  @param Returns the selected string. If the data wasn't a string,
    *         returns the following expression: 'It wasn't a string.'.
    *
    */
  char* toString(const int32 position_in_stack);



  // IS TYPE COMPARE

  /** @brief Checks if the selected position in the stack contains
    *         an integer.
    *
    *  @param Position_in_stack: data position in the stack.
    *  @return Returns 'true' if it was an integer; 'false' if not.
    *
    */
  bool isInteger(const int32 position_in_stack);

  /** @brief Checks if the selected position in the stack contains
    *         a float.
    *
    *  @param Position_in_stack: data position in the stack.
    *  @return Returns 'true' if it was a float; 'false' if not.
    *
    */
  bool isNumber(const int32 position_in_stack);

  /** @brief Checks if the selected position in the stack contains
    *         a boolean.
    *
    *  @param Position_in_stack: data position in the stack.
    *  @return Returns 'true' if it was a boolean; 'false' if not.
    *
    */
  bool isBoolean(const int32 position_in_stack);

  /** @brief Checks if the selected position in the stack contains
    *         a string.
    *
    *  @param Position_in_stack: data position in the stack.
    *  @return Returns 'true' if it was a string; 'false' if not.
    *
    */
  bool isString(const int32 position_in_stack);

  /** @brief Checks if the selected position in the stack contains
    *         a 'null' value.
    *
    *  @param Position_in_stack: data position in the stack.
    *  @return Returns 'true' if it was a 'null'; 'false' if not.
    *
    */
  bool isNil(const int32 position_in_stack);

  /** @brief Checks if the selected position in the stack contains
    *         a table.
    *
    *  @param Position_in_stack: data position in the stack.
    *  @return Returns 'true' if it was a table; 'false' if not.
    *
    */
  bool isTable(const int32 position_in_stack);

  /** @brief Checks if the selected position in the stack contains
    *         a function.
    *
    *  @param Position_in_stack: data position in the stack.
    *  @return Returns 'true' if it was a function; 'false' if not.
    *
    */
  bool isFunction(const int32 position_in_stack);

  /** @brief Checks if the selected position in the stack contains
    *         a C function.
    *
    *  @param Position_in_stack: data position in the stack.
    *  @return Returns 'true' if it was a C function; 'false' if not.
    *
    */
  bool isCFunction(const int32 position_in_stack);



  /****************************************
  ***          CUSTOM METHODS           ***
  ****************************************/

  /** @brief Method used to get an integer from a table.
    *
    *  Removes the table and the field from the stack before the
    *  end of the method.
    *
    *  @param Table: table name.
    *  @param Field: field name.
    *  @return Returns the selected integer.
    *
    */
  int32 getIntegerFromTable(const char* table, const char* field);

  /** @brief Method used to get a float from a table.
    *
    *  Removes the table and the field from the stack before the
    *  end of the method.
    *
    *  @param Table: table name.
    *  @param Field: field name.
    *  @return Returns the selected float.
    *
    */
  float getNumberFromTable(const char* table, const char* field);

  /** @brief Method used to get a boolean from a table.
    *
    *  Removes the table and the field from the stack before the
    *  end of the method.
    *
    *  @param Table: table name.
    *  @param Field: field name.
    *  @return Returns the selected boolean.
    *
    */
  bool getBooleanFromTable(const char* table, const char* field);

  /** @brief Method used to get a string from a table.
    *
    *  Removes the table and the field from the stack before the
    *  end of the method.
    *
    *  @param Table: table name.
    *  @param Field: field name.
    *
    *  @return Returns the selected string.
    *
    */
  char* getStringFromTable(const char* table, const char* field);

  /** @brief Gets an integer allocated in the index position of a table/array.
    *
    *  Removes the table and the field from the stack before the
    *  end of the method.
    *
    *  @param Table_name: Table where the field is contained.
    *  @param Index: Position in the table where the value is allocated.
    *
    *  @return The value of the field.
    *
    */
  int32 getIntegerFromArray(const char* table, const uint32 index);

  /** @brief Gets a number allocated in the index position of a table/array.
    *
    *  Removes the table and the field from the stack before the
    *  end of the method.
    *
    *  @param Table_name: Table where the field is contained.
    *  @param Index: Position in the table where the value is allocated.
    *
    *  @return The value of the field.
    *
    */
  double getNumberFromArray(const char* table, const uint32 index);

  /** @brief Gets a string allocated in the index position of a table/array.
    *
    *  Removes the table and the field from the stack before the
    *  end of the method.
    *
    *  @param Table_name: Table where the field is contained.
    *  @param Index: Position in the table where the value is allocated.
    *
    *  @return The value of the field.
    *
    */
  char* getStringFromArray(const char* table, const uint32 index);

  /** @brief Gets a boolean allocated in the index position of a table/array.
    *
    *  Removes the table and the field from the stack before the
    *  end of the method.
    *
    *  @param Table_name: Table where the field is contained.
    *  @param Index: Position in the table where the value is allocated.
    *
    *  @return The value of the field.
    *
    */
  bool getBooleanFromArray(const char* table, const uint32 index);

  
 private:
  struct lua_State* L_;
  Lua(const Lua&);
  Lua& operator=(const Lua &);

}; /* Lua class */
}; /* W2D */

#endif
