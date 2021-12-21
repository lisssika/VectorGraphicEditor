#pragma once
#include "Reader.h"
#include "GraphCommand.h"
#include <memory>

class Commander final
{
public:
	void add_and_execute_command(std::unique_ptr<IGraphCommand>cmd);
	void undo();
private:
	std::vector< std::unique_ptr<IGraphCommand>> history_;
};

