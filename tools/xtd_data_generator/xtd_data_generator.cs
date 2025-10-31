using System.Diagnostics;
using System.Globalization;
using System.Reflection;
using System.Text;

class xtd_data_generator {
  static void Main() {
    if (IsUsingNls()) {
      Console.ForegroundColor = ConsoleColor.Red;
      Console.WriteLine("ERROR: The current .NET runtime is not using ICU/CLDR for globalization.");
      Console.ResetColor();
      Environment.Exit(1);
    }

    var generationNumber = 0;
    var stopwatch = Stopwatch.StartNew();
    var version = 1;
    Console.OutputEncoding = Encoding.UTF8;
    Console.WriteLine("Start generations");
    WriteStatus("Generate Cultures", Execute(() => GenerateCultures(GetDataPathFile("cultures.bin"), version), ++generationNumber));
    WriteStatus("Generate DateTimeFormats", Execute(() => GenerateDateTimeFormats(GetDataPathFile("date_time_formats.bin"), version), ++generationNumber));
    WriteStatus("Generate NumberFormats", Execute(() => GenerateNumberFormats(GetDataPathFile("number_formats.bin"), version), ++generationNumber));
    WriteStatus("Generate Regions", Execute(() => GenerateRegions(GetDataPathFile("regions.bin"), version), ++generationNumber));
    WriteStatus("Generate TimeZones", Execute(() => GenerateTimeZones(GetDataPathFile("time_zones.bin"), version), ++generationNumber));
    stopwatch.Stop();
    Console.WriteLine($"End {generationNumber} generations ran. [{stopwatch.Elapsed.TotalSeconds:F4} seconds]");
    Environment.Exit(Environment.ExitCode);
  }

  static bool Execute(Action action, int generationNumber) {
    try {
      action();
      return true;
    } catch (Exception e) {
      Trace.WriteLine("ERROR: " + e.Message);
      Environment.ExitCode = generationNumber + 1;
      return false;
    }
  }

  static void GenerateCultures(string file_path, int version) {
    using (var bw = new System.IO.BinaryWriter(File.Open(file_path, FileMode.Create), Encoding.UTF8)) {
      WriteHeader(bw, "CULT", version);
      var cultures = CultureInfo.GetCultures(CultureTypes.AllCultures).OrderBy(culture => culture.Name).ToArray();
      bw.Write(cultures.Length);
      foreach (var cultureInfo in cultures) {
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
    }
  }

  static void GenerateDateTimeFormats(string file_path, int version) {
    using (var bw = new System.IO.BinaryWriter(File.Open(file_path, FileMode.Create), Encoding.UTF8)) {
      WriteHeader(bw, "DTFM", version);
      var cultures = CultureInfo.GetCultures(CultureTypes.AllCultures).OrderBy(culture => culture.Name).ToArray();
      bw.Write(cultures.Length);
      foreach (var cultureInfo in cultures) {
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
    }
  }

  static void GenerateNumberFormats(string file_path, int version) {
    using (var bw = new System.IO.BinaryWriter(File.Open(file_path, FileMode.Create), Encoding.UTF8)) {
      WriteHeader(bw, "NUMF", version);
      var cultures = CultureInfo.GetCultures(CultureTypes.AllCultures).OrderBy(culture => culture.Name).ToArray();
      bw.Write(cultures.Length);
      foreach (var cultureInfo in cultures) {
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
    }
  }

  static void GenerateRegions(string file_path, int version) {
    using (var bw = new System.IO.BinaryWriter(File.Open(file_path, FileMode.Create), Encoding.UTF8)) {
      WriteHeader(bw, "REGI", version);
      var cultures = CultureInfo.GetCultures(CultureTypes.AllCultures).Where(c => TryCreateRegion(c.Name, out _)).OrderBy(c => c.Name).ToArray();
      bw.Write(cultures.Length);
      foreach (var cultureInfo in cultures) {
        var region = new RegionInfo(cultureInfo.Name);
        bw.Write(cultureInfo.Name.ToLower());
        bw.Write(region.CurrencyEnglishName);
        bw.Write(region.CurrencyNativeName);
        bw.Write(region.CurrencySymbol);
        bw.Write(region.DisplayName);
        bw.Write(region.EnglishName);
        bw.Write(region.GeoId);
        bw.Write(region.IsMetric);
        bw.Write(region.ISOCurrencySymbol);
        bw.Write(region.Name);
        bw.Write(region.NativeName);
        bw.Write(region.ThreeLetterISORegionName);
        bw.Write(region.ThreeLetterWindowsRegionName);
        bw.Write(region.TwoLetterISORegionName);
      }
    }
  }

  static void GenerateTimeZones(string file_path, int version) {
    using (var bw = new System.IO.BinaryWriter(File.Open(file_path, FileMode.Create), Encoding.UTF8)) {
      WriteHeader(bw, "TZON", version);
      var timeZones = TimeZoneInfo.GetSystemTimeZones();
      bw.Write(timeZones.Count);
      foreach (var tz in timeZones.OrderBy(tz => tz.Id)) {
        bw.Write(tz.Id);
        bw.Write(tz.DisplayName);
        bw.Write(tz.StandardName);
        bw.Write(tz.DaylightName);
        bw.Write(tz.BaseUtcOffset.TotalMinutes);

        var adjustmentRules = tz.GetAdjustmentRules();
        bw.Write(adjustmentRules.Length);
        foreach (var rule in adjustmentRules) {
          bw.Write(rule.DateStart.ToBinary());
          bw.Write(rule.DateEnd.ToBinary());
          bw.Write(rule.DaylightDelta.TotalMinutes);

          bw.Write(rule.DaylightTransitionStart.IsFixedDateRule);
          bw.Write(rule.DaylightTransitionStart.Month);
          bw.Write(rule.DaylightTransitionStart.Week);
          bw.Write(rule.DaylightTransitionStart.Day);
          bw.Write((int)rule.DaylightTransitionStart.DayOfWeek);
          bw.Write(rule.DaylightTransitionStart.TimeOfDay.Ticks);

          bw.Write(rule.DaylightTransitionEnd.IsFixedDateRule);
          bw.Write(rule.DaylightTransitionEnd.Month);
          bw.Write(rule.DaylightTransitionEnd.Week);
          bw.Write(rule.DaylightTransitionEnd.Day);
          bw.Write((int)rule.DaylightTransitionEnd.DayOfWeek);
          bw.Write(rule.DaylightTransitionEnd.TimeOfDay.Ticks);
        }
      }
    }
  }
  
  static string GetDataPathFile(string file) {
    return Path.Combine(new[] {"..", "..", "..", "..", "..", "data", file});
  }

  static bool IsUsingNls() {
    var property = typeof(CultureInfo).Assembly.GetType("System.Globalization.GlobalizationMode")?.GetProperty("UseNls", BindingFlags.Static | BindingFlags.NonPublic);
    return property != null && (bool)property.GetValue(null)!;
  }

  static bool TryCreateRegion(string name, out RegionInfo region) {
    try {
      region = new RegionInfo(name);
      return true;
    } catch {
      region = null!;
      return false;
    }
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

  static void WriteHeader(BinaryWriter bw, string tag, int version) {
    bw.Write(new byte[] {(byte)'X', (byte)'T', (byte)'D', 0, (byte)tag[0], (byte)tag[1], (byte)tag[2], (byte)tag[3]});
    bw.Write(version);
  }
  
  static void WriteStatus(string title, bool success) {
    Console.WriteLine($"  {(success ? "✅" : "❌")} {title}");
  }
}
