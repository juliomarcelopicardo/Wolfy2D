#ifndef __ENGINELOG_MODULE_H__
#define __ENGINELOG_MODULE_H__ 1

#include <string>

#include "imgui\imgui.h"

namespace KYO {

/***************************************************************************/
/*                            FILE PATHS                                   */
/***************************************************************************/

/// Struct to hold all Log parameters.
const std::string kLogFile = "../data/log.txt";
const std::string kLogBackupFile = "../data/log_backup.txt";

/***************************************************************************/
/*                              LOG INFO                                   */
/***************************************************************************/


/// Struct to hold all Log parameters.
enum class LogParams {
  kNewFile = 0, // Removes previous log and makes new file
  kAppendText   // Appends Text to existing file
};


/***************************************************************************/
/*                                CLASS                                    */
/***************************************************************************/
class LoggerModule {
private:

  /// Whether the log is active or not.
  bool active_;
  /// Flag to prevent adding current daytime more than once
  bool addCurrentTimeOnce_;
  /// Flag to prevent backing up the log more than once
  bool backupLogOnce_;
  /// Automatically scrolls text down every line added
  bool scrollToBottom_;
  LogParams params_;
  ImGuiTextBuffer textBuffer_;
  /// Used to filter text when looking for specific strings
  ImGuiTextFilter textFilter_;
  ImVector<int> lineOffsets_;        // Index to lines offset
  /// Maximum buffer size (in chars) to be displayed.
  int maximum_buffer_size_;
  /// Shrink amount when buffer sice reaches its maximum.
  int shrink_quantity_;

  /**
  * @brief Makes a backup of the current log when adding
  *        the first line on application start.
  *        This prevents removing log file on application
  *        crash.
  */
  void MakeLogBackup();

  /**
  * @brief Obtains a formatted string with current time.
  * @param char* log_tag: log tag to add. for example [Warning].
  * @param std::string msg: msg to concatenate.
  * @return std::string "hh:mm log_tag msg".
  */
  std::string getCurrentTime(char* log_tag, std::string msg);

public:

  LoggerModule();
  ~LoggerModule();

  /// Clear the log data (only visual, log.txt isn't affected).
  void Clear();
  /**
  * @brief Add new text to the log as Info.
  * @param msg Message to add to the Log.
  * @param newline Wether the string will be placed in a new line or not.
  */
  void AddLog_I(std::string msg, bool newline = true, ...);
  /**
  * @brief Add new text to the log as Error.
  * @param msg Message to add to the Log.
  * @param newline Wether the string will be placed in a new line or not.
  */
  void AddLog_E(std::string msg, bool newline = true, ...);
  /**
  * @brief Add new text to the log as Warning.
  * @param msg Message to add to the Log.
  * @param newline Wether the string will be placed in a new line or not.
  */
  void AddLog_W(std::string msg, bool newline = true, ...);
  /**
  * @brief Draws the log on screen.
  * @param window_title Title of the log window.
  * @param p_open Flag to open/close the log window.
  */
  void Draw(const std::string& window_title, bool* p_open = NULL);

  /**
  * @brief Setter of LogParams (see struct LogParams in types.h).
  * @param param Log param to set.
  */
  void setLogParams(const LogParams param);
  /**
  * @brief Enables or disables the Log.
  * @param condition true to activate, false to deactivate.
  */
  void set_active(bool condition);

  /**
  * @brief Log status getter.
  * @return true if active, false if inactive.
  */
  bool active();

};

}


#endif
