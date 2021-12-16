#pragma once
#include <sstream>
#include "Reader.h"
#include "VectorFigure.h"
#include "GraphCommand.h"
#include <memory>

class Commander final
{
public:
	void add_and_execute_command(const std::shared_ptr<IGraphCommand>& cmd);
	void undo();
private:
	std::vector< std::shared_ptr<IGraphCommand>> history_;
};

