#include "VectorFigure.h"
#include <string>
#include <utility>

IVectorFigure::IVectorFigure(std::string name) : name_(std::move(name)) {}