#pragma once
#include <xtd/forms/form>

/// @brief Represents the ball widget application namespace.
namespace ball {
  /// @brief Represents the ball forms.
  /// @remarks The ball has two colors:
  ///  * ball::ball_form::color which represents the color of the ball.
  ///  * ball::ball_form::gradient_color2 which represents the color of the ball's light point to create a 3D effect.
  class ball_form : public xtd::forms::form {
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
    const xtd::drawing::color& color() const noexcept;
    /// @brief Sets the color of the ball.
    /// @param value The color of the ball.
    /// @return This current instance.
    ball_form& color(const xtd::drawing::color& value) noexcept;

    /// @brief Gets the color of the ball's light point to create a 3D effect.
    /// @return The the color of the ball's light point.
    const xtd::drawing::color& light_point_color() const noexcept;
    /// @brief Sets the color of the ball's light point to create a 3D effect
    /// @param value Thethe color of the ball's light point.
    /// @return This current instance.
    ball_form& light_point_color(const xtd::drawing::color& value) noexcept;
    
    /// @brief Gets the height and width of the ball.
    /// @return The size that represents the height and width of the ball in pixels.
    xtd::drawing::size size() const noexcept override;
    /// @brief Gets the height and width of the ball.
    /// @param value The size that represents the height and width of the ball in pixels.
    /// @return This current instance.
    control& size(const xtd::drawing::size& value) override;
    /// @)

  private:
    xtd::drawing::color color_;
    xtd::drawing::color light_point_color_;
  };
}
