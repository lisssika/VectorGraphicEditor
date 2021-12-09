#pragma once
class IGraphCommand {
public:
	virtual void redo() const = 0;
	virtual void undo() const = 0;
	virtual ~IGraphCommand() = default;
};