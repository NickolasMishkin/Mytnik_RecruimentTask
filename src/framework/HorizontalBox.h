#pragma once
#include "pch.h"
#include "widget.h"
#include <iostream>

namespace ui
{
	class HorizontalBox : public ui::Widget
	{
	public:

		HorizontalBox(Vector2f Position);

		void AddChild(WidgetPtr&& Child);

		virtual void Draw(RenderContext& Owner) const override;

		void Sort();

	private:

		void Initialize();

		std::vector <WidgetPtr> Childrens;

		Vector2f PositionOnViewport;
	};
}
