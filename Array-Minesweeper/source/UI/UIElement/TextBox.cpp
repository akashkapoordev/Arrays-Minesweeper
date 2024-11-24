#include "../../header/UI/UIElement/TextBox.h"

namespace UI
{
	namespace UIElement
	{
		TextBox::TextBox() = default;
	
		TextBox::~TextBox() = default;

		void TextBox::initialize(float width, float height, sf::Vector2f position, sf::Color color, sf::Color out_line_color, int thickness)
		{
			UIView::initialize();
			setScale(width, height);
			setBoxPosition(position);
			setBoxFillColor(color);
			setBoxOulineColor(out_line_color);
			setBoxThickness(thickness);

		}
		void TextBox::update()
		{
			UIView::render();
		}
		void TextBox::render()
		{
			UIView::render();
			if (UI::UIElement::UIView::ui_state == UIState::VISIBLE)
			{
				game_window->draw(box);

			}
		}
		void TextBox::show()
		{
			UIView::show();
		}
		void TextBox::setScale(float box_width, float box_height)
		{
			box.setSize(sf::Vector2f(box_width, box_height));
		}
		void TextBox::setBoxPosition(sf::Vector2f box_position)
		{
			box.setPosition(box_position);
		}
		void TextBox::setBoxFillColor(sf::Color box_color)
		{
			box.setFillColor(box_color);
		}
		void TextBox::setBoxOulineColor(sf::Color box_out_line_color)
		{
			box.setOutlineColor(box_out_line_color);
		}
		void TextBox::setBoxThickness(int box_thickness)
		{
			box.setOutlineThickness(box_thickness);
		}
		void TextBox::setBoxAlignCenter()
		{
			float x_position = (game_window->getSize().x / 2) - (box.getGlobalBounds().width / 2);
			float y_position = box.getGlobalBounds().getPosition().y;

			box.setPosition(x_position, y_position);
		}
	}
}