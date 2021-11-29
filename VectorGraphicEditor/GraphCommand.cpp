#pragma once
#include "GraphCommand.h"
#include "VectorFigure.h"
#include"Vector2D.h"

TranslateCommand::TranslateCommand(IVectorFigure* const figure_, Vector2D dxdy_) :figure(figure_), dxdy(dxdy_) {}
void TranslateCommand::redo() {
	figure->translate(dxdy);
}
void TranslateCommand::undo() {
	figure->translate({ -dxdy.x_coord, -dxdy.y_coord });
}

ScaleCommand::ScaleCommand(IVectorFigure* const figure_, double sx_, double sy_) :figure(figure_), sx(sx_), sy(sy_) {}
void ScaleCommand::redo() {
	figure->scale(sx, sy);
}
void ScaleCommand::undo() {
	figure->scale(1 / sx, 1 / sy);
}

RotateCommand::RotateCommand(IVectorFigure* const figure_, double deg_) :figure(figure_), deg(deg_) {}
void RotateCommand::redo() {
	figure->rotate(deg);
}
void RotateCommand::undo() {
	figure->rotate(-deg);
}
