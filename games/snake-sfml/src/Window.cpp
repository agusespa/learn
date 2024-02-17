#include "Window.h"

#include <SFML/Graphics.hpp>

using namespace std;

Window::Window(const string& title, const sf::Vector2u& size) {
    is_done = false;
    window_size = size;
    window.create({size.x, size.y, 32}, title,
                  sf::Style::Close | sf::Style::Titlebar);
}

Window::~Window() { window.close(); }

void Window::Update() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            is_done = true;
        }
    }
}

void Window::BeginDraw() { window.clear(sf::Color::Black); }

void Window::Draw(sf::Drawable& drawable) { window.draw(drawable); }

void Window::EndDraw() { window.display(); }

bool Window::IsDone() { return is_done; }

sf::RenderWindow* Window::GetRenderWindow() { return &window; }

sf::Vector2u Window::GetWindowSize() { return window_size; }
