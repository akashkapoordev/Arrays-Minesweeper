#pragma once
#include "../../UI/UIElement/UIView.h"
namespace UI
{
	namespace UIElement
	{
		

		class TextBox :public UIView
		{
			
		public:
			sf::RectangleShape box;
			TextBox();
			virtual ~TextBox();

			virtual void initialize(float width,float height,sf::Vector2f position,sf::Color color,sf::Color out_line_color,int thickness);
			virtual void update() override;
			virtual void render() override;

			virtual void show() override;
			
			virtual void setScale(float box_width, float box_height);
			virtual void setBoxPosition(sf::Vector2f box_position);
			virtual void setBoxFillColor(sf::Color box_color);
			virtual void setBoxOulineColor(sf::Color box_out_line_color);
			virtual void setBoxThickness(int box_thickness);
			virtual void setBoxAlignCenter();
		};
	}
}