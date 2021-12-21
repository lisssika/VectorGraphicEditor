#include "Commander.h"
#include <memory>

void Commander::add_and_execute_command(std::unique_ptr<IGraphCommand> cmd)
{
	cmd->redo();
	history_.push_back(std::move(cmd));
}

void Commander::undo()
{
	if (history_.empty()) return;
	history_.at(history_.size()-1)->undo();
	history_.pop_back();
}
