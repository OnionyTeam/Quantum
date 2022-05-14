#ifndef _QUANTUM_KEYMAP_H__
#define _QUANTUM_KEYMAP_H__

#include <map>
#include <string>
#include <functional>
#include "../command/command.h"

class Editor;

const static std::map<std::string, std::function<void(Editor*)>> key_map {
    {"Command::MoveUp", Command::cursor_move_up},
    {"Command::MoveDown", Command::cursor_move_down},
};


#endif //_QUANTUM_KEYMAP_H__