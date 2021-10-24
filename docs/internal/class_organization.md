# Class organization

## Classic C++

In c++ classqiue, members are organized by their access level: public, protected and private like this:

```c++
class my_class {
public:
  my_class(int value_a, int value_b) : value_a(value_a), value_b_(value_b) {}
  my_class(const my_class&) = default;
  
  int value_a() const noexcept {return value_a_;}
  
  int value_b() const noexcept {return value_b_;}
  
protected:
  my_class() = default;
  
  void value_a(int value) noexcept {value_a_ = value;}
  void value_b(int value) noexcept {value_b_ = value;}
  
private:
  int value_a_ = 0;
  int value_b_ = 0;
};
```

## Proposal for xtd

It would make more sense to group mebmres by functionality and not by access. I imagine something like this:

```c++
class my_class {
  protected_ my_class() = default;
  public_ my_class(int value_a, int value_b) : value_a(value_a), value_b_(value_b) {}
  public_ my_class(const my_class&) = default;
  
  private_ int value_a_ = 0;
  public_ int value_a() const noexcept {return value_a_;}
  protected_ void value_a(int value) noexcept {value_a_ = value;}
  
  private_ int value_b_ = 0;
  public_ int value_b() const noexcept {return value_b_;}
  protected_ void value_b(int value) noexcept {value_b_ = value;}    
};
```

To be able to write a class like above, you obviously need three more keywords (there are already some like abastract_, interface_, ...).

```c++
#define private_ private
#define protected_ protected
#define public_ public
```

## Conclusion

There is just one problem but it is not really a problem if you get used to describe all the time like this.
It is that if you forget one of the keywords to a member, it is the keyword of the previous member that will be applied...

It changes the way of writing but the organization is much clearer.
It looks much more like a modern language like Java or CSharp.
