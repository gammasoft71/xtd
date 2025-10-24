using System.Diagnostics;
using System.Globalization;
using System.Reflection;
using System.Text;

class GenerateCultureInfoCpp {
  static void Main() {
    Console.WriteLine("Generation started");
    if (IsUsingNls()) {
      Trace.WriteLine("ERROR: The current .NET runtime is not using ICU/CLDR for globalization.");
      Environment.Exit(1);
    }

    var xtdDataPath = Path.Combine(new[] { "..", "..", "..", "..", "..", "data" });
    var version = 1;
    Console.Write("  * Generate Cultures...        ");
    Console.WriteLine(GenerateCultures(Path.Combine(new[] {xtdDataPath, "cultures.bin"}), version) ? "[SUCCEED]" : "[FAILED ]");
    Console.Write("  * Generate DateTimeFormats... ");
    Console.WriteLine(GenerateDateTimeFormats(Path.Combine(new[] {xtdDataPath, "date_time_formats.bin"}), version) ? "[SUCCEED]" : "[FAILED ]");
    Console.Write("  * Generate NumberFormats...   ");
    Console.WriteLine(GenerateNumberFormats(Path.Combine(new[] {xtdDataPath, "number_formats.bin"}), version) ? "[SUCCEED]" : "[FAILED ]");
    Console.Write("  * Generate TimeZones...       ");
    Console.WriteLine(GenerateTimeZones(Path.Combine(new[] {xtdDataPath, "time_zones.bin"}), version) ? "[SUCCEED]" : "[FAILED ]");
    Console.WriteLine("Generation ended");
    Environment.Exit(Environment.ExitCode);
  }

  static bool GenerateCultures(string file_path, int version) {
    try {
      var bw = new System.IO.BinaryWriter(File.Open(file_path, FileMode.Create), Encoding.UTF8);
      bw.Write(new byte[] {(byte)'X', (byte)'T', (byte)'D', 0, (byte)'C', (byte)'U', (byte)'L', (byte)'T'});
      bw.Write(version);
      var cultures = CultureInfo.GetCultures(CultureTypes.AllCultures);
      bw.Write(cultures.Length);
      foreach (var cultureInfo in cultures.OrderBy(culture => culture.Name)) {
        bw.Write(cultureInfo.Name.ToLower());
        bw.Write((int)(cultureInfo.CultureTypes & CultureTypes.AllCultures));
        bw.Write(cultureInfo.DisplayName);
        bw.Write(cultureInfo.EnglishName);
        bw.Write(cultureInfo.KeyboardLayoutId);
        bw.Write(cultureInfo.LCID);
        bw.Write(cultureInfo.Name);
        bw.Write(cultureInfo.NativeName);
        bw.Write(cultureInfo.Parent.Name);
        bw.Write(cultureInfo.ThreeLetterISOLanguageName);
        bw.Write(cultureInfo.ThreeLetterWindowsLanguageName);
        bw.Write(cultureInfo.TwoLetterISOLanguageName);
      }
      bw.Close();
      return true;
    } catch (Exception e) {
      Trace.WriteLine("ERROR: " + e.Message);
      Environment.ExitCode = 2;
      return false;
    }
  }

  static bool GenerateDateTimeFormats(string file_path, int version) {
    try {
      var bw = new System.IO.BinaryWriter(File.Open(file_path, FileMode.Create), Encoding.UTF8);
      bw.Write(new byte[] {(byte)'X', (byte)'T', (byte)'D', 0, (byte)'D', (byte)'T', (byte)'F'});
      bw.Write(version);
      var cultures = CultureInfo.GetCultures(CultureTypes.AllCultures);
      bw.Write(cultures.Length);
      foreach (var cultureInfo in cultures.OrderBy(culture => culture.Name)) {
        bw.Write(cultureInfo.Name.ToLower());
        Write(bw, cultureInfo.DateTimeFormat.AbbreviatedDayNames);
        Write(bw, cultureInfo.DateTimeFormat.AbbreviatedMonthGenitiveNames);
        Write(bw, cultureInfo.DateTimeFormat.AbbreviatedMonthNames);
        bw.Write(cultureInfo.DateTimeFormat.AMDesignator);
        bw.Write(cultureInfo.DateTimeFormat.DateSeparator);
        Write(bw, cultureInfo.DateTimeFormat.DayNames);
        bw.Write((int)cultureInfo.DateTimeFormat.FirstDayOfWeek);
        bw.Write(cultureInfo.DateTimeFormat.FullDateTimePattern);
        bw.Write(cultureInfo.DateTimeFormat.LongDatePattern);
        bw.Write(cultureInfo.DateTimeFormat.LongTimePattern);
        bw.Write(cultureInfo.DateTimeFormat.MonthDayPattern);
        Write(bw, cultureInfo.DateTimeFormat.MonthGenitiveNames);
        Write(bw, cultureInfo.DateTimeFormat.MonthNames);
        bw.Write(cultureInfo.DateTimeFormat.NativeCalendarName);
        bw.Write(cultureInfo.DateTimeFormat.PMDesignator);
        bw.Write(cultureInfo.DateTimeFormat.RFC1123Pattern);
        bw.Write(cultureInfo.DateTimeFormat.ShortDatePattern);
        bw.Write(cultureInfo.DateTimeFormat.ShortTimePattern);
        Write(bw, cultureInfo.DateTimeFormat.ShortestDayNames);
        bw.Write(cultureInfo.DateTimeFormat.SortableDateTimePattern);
        bw.Write(cultureInfo.DateTimeFormat.TimeSeparator);
        bw.Write(cultureInfo.DateTimeFormat.UniversalSortableDateTimePattern);
        bw.Write(cultureInfo.DateTimeFormat.YearMonthPattern);
      }
      bw.Close();
      return true;
    } catch (Exception e) {
      Trace.WriteLine("ERROR: " + e.Message);
      Environment.ExitCode = 3;
      return false;
    }
  }

  static bool GenerateNumberFormats(string file_path, int version) {
    try {
      var bw = new System.IO.BinaryWriter(File.Open(file_path, FileMode.Create), Encoding.UTF8);
      bw.Write(new byte[] {(byte)'X', (byte)'T', (byte)'D', 0, (byte)'N', (byte)'B', (byte)'F'});
      bw.Write(version);
      var cultures = CultureInfo.GetCultures(CultureTypes.AllCultures);
      bw.Write(cultures.Length);
      foreach (var cultureInfo in cultures.OrderBy(culture => culture.Name)) {
        bw.Write(cultureInfo.Name.ToLower());
        bw.Write(cultureInfo.NumberFormat.CurrencyDecimalDigits);
        bw.Write(cultureInfo.NumberFormat.CurrencyDecimalSeparator);
        bw.Write(cultureInfo.NumberFormat.CurrencyGroupSeparator);
        Write(bw, cultureInfo.NumberFormat.CurrencyGroupSizes);
        bw.Write(cultureInfo.NumberFormat.CurrencyNegativePattern);
        bw.Write(cultureInfo.NumberFormat.CurrencyPositivePattern);
        bw.Write(cultureInfo.NumberFormat.CurrencySymbol);
        bw.Write((int)cultureInfo.NumberFormat.DigitSubstitution);
        bw.Write(cultureInfo.NumberFormat.NaNSymbol);
        bw.Write(cultureInfo.NumberFormat.NegativeInfinitySymbol);
        bw.Write(cultureInfo.NumberFormat.NegativeSign);
        bw.Write(cultureInfo.NumberFormat.NumberDecimalDigits);
        bw.Write(cultureInfo.NumberFormat.NumberDecimalSeparator);
        bw.Write(cultureInfo.NumberFormat.NumberGroupSeparator);
        Write(bw, cultureInfo.NumberFormat.NumberGroupSizes);
        bw.Write(cultureInfo.NumberFormat.NumberNegativePattern);
        bw.Write(cultureInfo.NumberFormat.PercentDecimalDigits);
        bw.Write(cultureInfo.NumberFormat.PercentDecimalSeparator);
        bw.Write(cultureInfo.NumberFormat.PercentGroupSeparator);
        Write(bw, cultureInfo.NumberFormat.PercentGroupSizes);
        bw.Write(cultureInfo.NumberFormat.PercentNegativePattern);
        bw.Write(cultureInfo.NumberFormat.PercentPositivePattern);
        bw.Write(cultureInfo.NumberFormat.PercentSymbol);
        bw.Write(cultureInfo.NumberFormat.PerMilleSymbol);
        bw.Write(cultureInfo.NumberFormat.PositiveInfinitySymbol);
        bw.Write(cultureInfo.NumberFormat.PositiveSign);
      }
      bw.Close();
      return true;
    } catch (Exception e) {
      Trace.WriteLine("ERROR: " + e.Message);
      Environment.ExitCode = 3;
      return false;
    }
  }

  static bool GenerateTimeZones(string file_path, int version) {
    Trace.WriteLine("ERROR: Not yet implemented.");
    Environment.ExitCode = 4;
    return false;
  }

  static bool IsUsingNls()
  {
    var property = typeof(CultureInfo).Assembly.GetType("System.Globalization.GlobalizationMode")?.GetProperty("UseNls", BindingFlags.Static | BindingFlags.NonPublic);
    return property != null && (bool)property.GetValue(null)!;
  }
  
  static void Write(BinaryWriter bw, int[] values) {
    bw.Write(values.Length);
    foreach (var value in values)
      bw.Write(value);
  }
  
  static void Write(BinaryWriter bw, string[] values) {
    bw.Write(values.Length);
    foreach (var value in values)
      bw.Write(value);
  }
}
