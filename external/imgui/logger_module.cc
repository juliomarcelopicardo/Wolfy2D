#include "imgui/logger_module.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include "time.h"
#include <sstream>
#include <time.h>
#include <stdio.h>


/******************************************************************************/
/*                            PRIVATE METHODS                                 */
/******************************************************************************/

namespace KYO {

void LoggerModule::MakeLogBackup() {

  std::ifstream infile;
  std::ofstream outfile;
  std::string content = "";

  infile.open(kLogFile.c_str());
  outfile.open(kLogBackupFile.c_str());

  // Copy contents of log.txt to content
  for (int i = 0; infile.eof() != true; i++) {
    content += infile.get();
  }

  // Erase last character
  content.erase(content.end() - 1);
  infile.close();

  // Copy all the content to the output file
  outfile << content;
  outfile.close();
}

std::string LoggerModule::getCurrentTime(char* log_tag, std::string msg) {
  time_t rawtime;
  struct tm ptm;
  time(&rawtime);
  gmtime_s(&ptm, &rawtime);
  char buffr[50];
  sprintf_s(buffr, "%02d", ptm.tm_min);
  std::ostringstream stringStream;
  // the -2 is for UK time GMT+0
  stringStream << " " << (((ptm.tm_hour) + 2 % 24) - 2) << ":" << buffr;
  stringStream << " " << log_tag << " " << msg.c_str();
  std::string copyOfStr = stringStream.str();
  return copyOfStr;
}


/******************************************************************************/
/*                             PUBLIC METHODS                                 */
/******************************************************************************/


LoggerModule::LoggerModule() {
  addCurrentTimeOnce_ = false;
  backupLogOnce_ = false;
  active_ = true;
  params_ = LogParams::kAppendText;
  maximum_buffer_size_ = 10000;
  shrink_quantity_ = 3000;
}

LoggerModule::~LoggerModule() {

}

void LoggerModule::Clear() {
  textBuffer_.clear();
  lineOffsets_.clear();
}

void LoggerModule::AddLog_I(std::string msg, bool newline, ...) {

  std::ofstream logfile;

  if (!backupLogOnce_) {
    // Open close the file.
    // This prevents error if log.txt doesn't exist.
    logfile.open("../data/log.txt", std::ios::ate | std::ios::app);
    logfile.close();
    MakeLogBackup();
    backupLogOnce_ = true;
  }

  int old_size = textBuffer_.size();
  va_list args;
  va_start(args, msg);

  // Only for IMGUI visual format.
  // Doesn't copy the msg to log.txt with the newline.
  if (newline) {
    msg.push_back('\n');
  }

  textBuffer_.appendfv(getCurrentTime("[Info]", msg).c_str(), args);

  va_end(args);

  for (int new_size = textBuffer_.size(); old_size < new_size; old_size++) {
    if (textBuffer_[old_size] == '\n') {
      lineOffsets_.push_back(old_size);
      scrollToBottom_ = true;
    }
  }

  switch (params_) {
  case LogParams::kAppendText: {
    logfile.open("../data/log.txt", std::ios::ate | std::ios::app);
    break;
  }
  case LogParams::kNewFile: {
    logfile.open("../data/log.txt", std::ios::ate | std::ios::trunc);
    // Return to AppendText to prevent creating a new file
    // everytime we add a new line.
    params_ = LogParams::kAppendText;
    break;
  }
  default: break;
  }


  if (!addCurrentTimeOnce_) {
    char str2[26];
    std::chrono::time_point<std::chrono::system_clock> end;
    end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    logfile << ctime_s(str2, sizeof str2, &end_time)
      << "-------------------------\n";
    addCurrentTimeOnce_ = true;
  }

  if (newline) {
    msg.pop_back();
  }

  logfile << msg.c_str() << "\n";
  logfile.close();
}

void LoggerModule::AddLog_E(std::string msg, bool newline /*= true*/, ...) {
  std::ofstream logfile;

  if (!backupLogOnce_) {
    // Open close the file.
    // This prevents error if log.txt doesn't exist.
    logfile.open("../data/log.txt", std::ios::ate | std::ios::app);
    logfile.close();
    MakeLogBackup();
    backupLogOnce_ = true;
  }

  int old_size = textBuffer_.size();
  va_list args;
  va_start(args, msg);

  // Only for IMGUI visual format.
  // Doesn't copy the msg to log.txt with the newline.
  if (newline) {
    msg.push_back('\n');
  }

  textBuffer_.appendfv(getCurrentTime("[Error]", msg).c_str(), args);

  va_end(args);

  for (int new_size = textBuffer_.size(); old_size < new_size; old_size++) {
    if (textBuffer_[old_size] == '\n') {
      lineOffsets_.push_back(old_size);
      scrollToBottom_ = true;
    }
  }

  switch (params_) {
  case LogParams::kAppendText: {
    logfile.open("../data/log.txt", std::ios::ate | std::ios::app);
    break;
  }
  case LogParams::kNewFile: {
    logfile.open("../data/log.txt", std::ios::ate | std::ios::trunc);
    // Return to AppendText to prevent creating a new file
    // everytime we add a new line.
    params_ = LogParams::kAppendText;
    break;
  }
  default: break;
  }


  if (!addCurrentTimeOnce_) {
    char str2[26];
    std::chrono::time_point<std::chrono::system_clock> end;
    end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    ctime_s(str2, sizeof str2, &end_time);
    logfile << str2 << "-------------------------\n";
    addCurrentTimeOnce_ = true;
  }

  if (newline) {
    msg.pop_back();
  }

  logfile << msg.c_str() << "\n";
  logfile.close();
}

void LoggerModule::AddLog_W(std::string msg, bool newline /*= true*/, ...) {
  std::ofstream logfile;

  if (!backupLogOnce_) {
    // Open close the file.
    // This prevents error if log.txt doesn't exist.
    logfile.open("../data/log.txt", std::ios::ate | std::ios::app);
    logfile.close();
    MakeLogBackup();
    backupLogOnce_ = true;
  }

  int old_size = textBuffer_.size();
  va_list args;
  va_start(args, msg);

  // Only for IMGUI visual format.
  // Doesn't copy the msg to log.txt with the newline.
  if (newline) {
    msg.push_back('\n');
  }

  textBuffer_.appendfv(getCurrentTime("[Warning]", msg).c_str(), args);

  va_end(args);

  for (int new_size = textBuffer_.size(); old_size < new_size; old_size++) {
    if (textBuffer_[old_size] == '\n') {
      lineOffsets_.push_back(old_size);
      scrollToBottom_ = true;
    }
  }

  switch (params_) {
  case LogParams::kAppendText: {
    logfile.open("../data/log.txt", std::ios::ate | std::ios::app);
    break;
  }
  case LogParams::kNewFile: {
    logfile.open("../data/log.txt", std::ios::ate | std::ios::trunc);
    // Return to AppendText to prevent creating a new file
    // everytime we add a new line.
    params_ = LogParams::kAppendText;
    break;
  }
  default: break;
  }


  if (!addCurrentTimeOnce_) {
    char str2[26];
    std::chrono::time_point<std::chrono::system_clock> end;
    end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    logfile << ctime_s(str2, sizeof str2, &end_time)
      << "-------------------------\n";
    addCurrentTimeOnce_ = true;
  }

  if (newline) {
    msg.pop_back();
  }

  logfile << msg.c_str() << "\n";
  logfile.close();
}

void LoggerModule::Draw(const std::string& window_title, bool* p_open) {
  if (ImGui::Button("Clear")) Clear();
  ImGui::SameLine();
  bool copy = ImGui::Button("Copy all log to clipboard");
  ImGui::SameLine();
  textFilter_.Draw("Filter", -100.0f);
  ImGui::Separator();
  ImGui::BeginChild("scrolling", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);
  if (copy) ImGui::LogToClipboard();

  if (textFilter_.IsActive()) {
    const char* textBuffer__begin = textBuffer_.begin();
    const char* line = textBuffer__begin;
    for (int line_no = 0; line != NULL; line_no++) {
      const char* line_end = (line_no < lineOffsets_.Size) ? textBuffer__begin + lineOffsets_[line_no] : NULL;
      if (textFilter_.PassFilter(line, line_end)) {
        ImGui::TextUnformatted(line, line_end);
      }
      line = line_end && line_end[1] ? line_end + 1 : NULL;
    }
  }
  else {
    //ImGui::Text(textBuffer_.begin());
    const char* textBuffer__begin = textBuffer_.begin();
    std::string lines;
    std::vector<std::string> sentences;
    for (int i = 0; i < textBuffer_.size(); i++) {
      switch (textBuffer_[i]) {
      case '\n': {
        // End sentence
        sentences.push_back(lines);
        lines.clear();
        break;
      }
      default: lines.push_back(textBuffer_[i]); break;
      }
    }

    for (unsigned int i = 0; i < sentences.size(); i++) {
      ImVec4 col = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
      if (strstr(sentences[i].c_str(), "[Error]")) {
        col = ImColor(1.0f, 0.4f, 0.4f, 1.0f);
      }
      else if (strstr(sentences[i].c_str(), "[Warning]")) {
        col = ImColor(1.0f, 1.0f, 0.0f, 1.0f);
      }
      ImGui::PushStyleColor(ImGuiCol_Text, col);
      ImGui::TextUnformatted(sentences[i].c_str());
      ImGui::PopStyleColor();
    }
    sentences.clear();
  }

  // Prevent collapsing memory
  // Copies (maximum_buffer_size - shrink_quantity) characters to the log
  // and deletes the shrinked ones. Shrinks from top meaning that the messages
  // deleted are the older ones.
  if (textBuffer_.size() > maximum_buffer_size_) {
    size_t copysize = ((maximum_buffer_size_ - shrink_quantity_) + 30);
    char* copy_buffer = new char[copysize * sizeof(char)];
    strncpy_s(copy_buffer, copysize * sizeof(char),
      textBuffer_.begin() + shrink_quantity_,
      maximum_buffer_size_ - shrink_quantity_);
    textBuffer_.clear();
    textBuffer_.appendf(copy_buffer);
    delete copy_buffer;
  }

  if (scrollToBottom_)
    ImGui::SetScrollHere(1.0f);
  scrollToBottom_ = false;
  ImGui::EndChild();
}

/*###################################*/
/*##            SETTERS            ##*/
/*###################################*/

void LoggerModule::setLogParams(const LogParams param) {
  params_ = param;
}

void LoggerModule::set_active(bool condition) {
  active_ = condition;
}

/*###################################*/
/*##            GETTERS            ##*/
/*###################################*/

bool LoggerModule::active() {
  return active_;
}


}