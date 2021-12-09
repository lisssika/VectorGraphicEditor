#include "Commander.h"
#include <memory>

void Commander::add_and_execute_command(const std::shared_ptr<IGraphCommand>& cmd)
{
	history_.push_back(cmd);
	cmd->redo();
}

void Commander::undo()
{
	if (history_.empty()) return;
	const auto cmd = history_.back();
	cmd->undo();
	history_.pop_back();
}
