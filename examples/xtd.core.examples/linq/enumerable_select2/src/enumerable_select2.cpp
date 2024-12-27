#include <xtd/collections/generic/list>
#include <xtd/console>

using namespace xtd;
using namespace xtd::linq;
using namespace xtd::collections::generic;

struct contact_info : istringable {
  contact_info() = default;
  contact_info(int id, const string& email, const string& phone) : id {id}, email {email}, phone {phone} {}
  
  int id = 0;
  string email;
  string phone;
  
  string to_string() const noexcept override {return string::format("{},{}", email, phone);};
};

struct score_info {
  double average = .0;
  int id = 0;
};

struct student : istringable {
  student() = default;
  student(const string& first, const string& last, int id, const list<int>& scores) : first {first}, last {last}, id {id}, scores {scores} {}
  
  string first;
  string last;
  int id = 0;
  list<int> scores;
  
  static contact_info get_contact_info(const auto& contact_list, int id) noexcept {
    contact_info cinfo =
      from(contact_list)
      .where([&](const auto& value) {return value.id == id;})
      .first_or_default();
    return cinfo;
  }
  
  string to_string() const noexcept override {return string::format("{} {}:{}", first, last, id);};
};

auto main() -> int {
  // The primary data source
  auto students = {
    student {"Svetlana", "Omelchenko", 111, {97, 92, 81, 60}},
    student {"Claire", "O'Donnell", 112, {75, 84, 91, 39}},
    student {"Sven", "Mortensen", 113, {88, 94, 65, 91}},
    student {"Cesar", "Garcia", 114, {97, 89, 85, 82}}
  };
  
  // Separate data source for contact info.
  auto contact_list = {
    contact_info {111, "SvetlanO@Contoso.com", "206-555-0108"},
    contact_info {112, "ClaireO@Contoso.com", "206-555-0298"},
    contact_info {113, "SvenMort@Contoso.com", "206-555-1130"},
    contact_info {114, "CesarGar@Contoso.com", "206-555-0521"}
  };
  
  // Produce a filtered sequence of unmodified students.
  const ienumerable<student>& student_query1 =
    from(students)
    .where([](const student& student) {return student.id > 111;})
    .select([](const student& student) {return student;});

  console::write_line("student_query1: select range_variable");
  for (const student& student : student_query1)
    console::write_line(student);
  
  // Produce a filtered sequence of elements that contain only one property of each student.
  const ienumerable<string>& student_query2 =
    from(students)
    .where([](const student& student) {return student.id > 111;})
    .select<string>([](const student& student) {return student.last;});
  
  console::write_line();
  console::write_line("student_query2: select range_variable.property");
  for (const string& last : student_query2)
    console::write_line(last);
  
  // Produce a filtered sequence of objects created by a method call on each student.
  const ienumerable<contact_info>& student_query3 =
    from(students)
    .where([](const student& student) {return student.id > 111;})
    .select<contact_info>([&](const student& student) {return student.get_contact_info(contact_list, student.id);});
  
  console::write_line();
  console::write_line("student_query3: select range_variable.method");
  for (const contact_info& contact_info : student_query3)
    console::write_line(contact_info);
  
  // Produce a filtered sequence of ints from the internal array inside each student.
  const ienumerable<int>& student_query4 =
    from(students)
    .where([](const student& student) {return student.id > 111;})
    .select<int>([](const student& student) {return student.scores[0];});
  
  console::write_line();
  console::write_line("student_query4: select range_variable[index]");
  for (int score : student_query4)
    console::write_line("First score = {}", score);
  
  // Produce a filtered sequence of doubles that are the result of an expression.
  const ienumerable<double>& student_query5 =
    from(students)
    .where([](const student& student) {return student.id > 111;})
    .select<double>([](const student& student) {return student.scores[0] * 1.1;});
  
  console::write_line();
  console::write_line("student_query5: select expression");
  for (double adjusted_score : student_query5)
    console::write_line("Adjusted first score = {}", adjusted_score);
  
  // Produce a filtered sequence of doubles that are the result of a method call.
  const ienumerable<double>& student_query6 =
    from(students)
    .where([](const student& student) {return student.id > 111;})
    .select<double>([](const student& student) {return student.scores.average();});
  
  console::write_line();
  console::write_line("student_query6: select expression2");
  for (double average : student_query6)
    console::write_line("Average = {}", average);
  
  // Produce a filtered sequence of tuple type that contain only two properties from each student.
  const auto& student_query7 =
    from(students)
    .where([](const student& student) {return student.id > 111;})
    .select<std::tuple<string, string>>([](const student& student) {return std::make_tuple(student.first, student.last);});
  
  console::write_line();
  console::write_line("student_query7: select tuple type");
  for (const auto& [first, last] : student_query7)
    console::write_line("{}, {}", last, first);
  
  
  // Produce a filtered sequence of named objects that contain a method return value and a property from each student.
  // Use named types if you need to pass the query variable across a method boundary.
  const auto& student_query8 =
    from(students)
    .where([](const student& student) {return student.id > 111;})
    .select<score_info>([](const student& student) {return score_info {.average = student.scores.average(), .id = student.id};});
  
  console::write_line();
  console::write_line("student_query8: select named type");
  for (const score_info& score_info : student_query8)
    console::write_line("ID = {}, Average = {}", score_info.id, score_info.average);
}

// This code produces the following output :
//
// student_query1: select range_variable
// Claire O'Donnell:112
// Sven Mortensen:113
// Cesar Garcia:114
//
// student_query2: select range_variable.property
// O'Donnell
// Mortensen
// Garcia
//
// student_query3: select range_variable.method
// ClaireO@Contoso.com,206-555-0298
// SvenMort@Contoso.com,206-555-1130
// CesarGar@Contoso.com,206-555-0521
//
// student_query4: select range_variable[index]
// First score = 75
// First score = 88
// First score = 97
//
// student_query5: select expression
// Adjusted first score = 82.5
// Adjusted first score = 96.8
// Adjusted first score = 106.7
//
// student_query6: select expression2
// Average = 72.25
// Average = 84.5
// Average = 88.25
//
// student_query7: select tuple type
// O'Donnell, Claire
// Mortensen, Sven
// Garcia, Cesar
//
// student_query8: select named type
// ID = 112, Average = 72.25
// ID = 113, Average = 84.5
// ID = 114, Average = 88.25
