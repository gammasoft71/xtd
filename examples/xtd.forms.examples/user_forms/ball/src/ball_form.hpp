#pragma once
#include <xtd/xtd>

/// @brief Represents the ball widget application namespace.
namespace ball {
  /// @brief Represents the ball forms.
  /// @remarks The ball has two colors:
  ///  * ball::ball_form::color which represents the color of the ball.
  ///  * ball::ball_form::gradient_color2 which represents the color of the ball's light point to create a 3D effect.
  class ball_form : public form {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Initialises a new instance of ball::ball_form class.
    ball_form();
    /// @)
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets the color of the ball.
    /// @return The color ball.
    const drawing::color& color() const noexcept;
    /// @brief Sets the color of the ball.
    /// @param value The color of the ball.
    /// @return This current instance.
    ball_form& color(const drawing::color& value) noexcept;

    /// @brief Gets the color of the ball's light point to create a 3D effect.
    /// @return The the color of the ball's light point.
    const drawing::color& light_point_color() const noexcept;
    /// @brief Sets the color of the ball's light point to create a 3D effect
    /// @param value Thethe color of the ball's light point.
    /// @return This current instance.
    ball_form& light_point_color(const drawing::color& value) noexcept;
    
    /// @brief Gets the height and width of the ball.
    /// @return The size that represents the height and width of the ball in pixels.
    drawing::size size() const noexcept override;
    /// @brief Gets the height and width of the ball.
    /// @param value The size that represents the height and width of the ball in pixels.
    /// @return This current instance.
    control& size(const drawing::size& value) override;
    /// @)

  protected:
    /// @name Portected Methods
    
    /// @{
    /// @brief Raises the xtd::forms::control::paint event.
    /// @param e An xtd::event_args that contains the event data.
    void on_paint(paint_event_args& e) override;
    /// @)

  private:
    drawing::color color_;
    drawing::color light_point_color_;
  };
}
