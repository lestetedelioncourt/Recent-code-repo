==> learnwpfexercises/BikeShop/BikeShop/App.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace BikeShop
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
    }
}

==> learnwpfexercises/BikeShop/BikeShop/Contact.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace BikeShop
{
    /// <summary>
    /// Interaction logic for Contact.xaml
    /// </summary>
    public partial class Contact : Page
    {
        public Contact()
        {
            InitializeComponent();
        }
    }
}

==> learnwpfexercises/BikeShop/BikeShop/Discussion.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace BikeShop
{
    /// <summary>
    /// Interaction logic for Discussion.xaml
    /// </summary>
    public partial class Discussion : Page
    {
        public Discussion()
        {
            InitializeComponent();
        }
    }
}

==> learnwpfexercises/BikeShop/BikeShop/MainWindow.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace BikeShop
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
    }
}

==> learnwpfexercises/BikeShop/BikeShop/Menu.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace BikeShop
{
    /// <summary>
    /// Interaction logic for Menu.xaml
    /// </summary>
    public partial class Menu : Page
    {
        public Menu()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(
              new Uri("/Contact.xaml", UriKind.Relative)
            );
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(
              new Uri("/Discussion.xaml", UriKind.Relative)
            );
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(
              new Uri("/ProductsManagementMVVM.xaml", UriKind.Relative)
            );
        }
    }
}

==> learnwpfexercises/BikeShop/BikeShop/Notifier.cs <==
﻿using System.ComponentModel;

public class Notifier : INotifyPropertyChanged
{
    public event PropertyChangedEventHandler PropertyChanged;

    protected void OnPropertyChanged(string propertyName)
    {
        if (PropertyChanged != null)
        {
            PropertyChanged(this,
                new PropertyChangedEventArgs(propertyName));
        }
    }
}

==> learnwpfexercises/BikeShop/BikeShop/ProductsFactory.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BikeShop
{
    public class ProductsFactory
    {
        public IEnumerable<Product> GetAllProducts()
        {
            return products;
        }

        public IEnumerable<Product> FindProducts(string searchString)
        {
            return products.Where(p => p.Title.Contains(searchString));
        }

        #region In-memory data
        // This code builds an in-memory product collection
        // but we could as well fectch it from a database
        // or web service and it would yield the same result.
        static IList<Product> products;
        static ProductsFactory()
        {
            products = new List<Product>();
            for (int i = 0; i < 100; i++)
            {
                products.Add(generateRandomProduct());
            }
        }

        static Random r = new Random(DateTime.Now.Millisecond);
        static Product generateRandomProduct()
        {
            var titles = new string[] { "Classic city bike", "Vintage city bike", "Basic mountain bike", "Easy mountain bike", "Devil mountain bike" };
            var colors = new string[] { "Red", "Blue", "Green", "Brown", "Gray", "Black" };
            return new Product()
            {
                Title = pickRandom(titles),
                Color = pickRandom(colors),
                Price = Math.Round(300M + (decimal)r.NextDouble() * 1700M, 2),
                Reference = "BK"+r.Next(100000).ToString("d8")
            };
        }
        static T pickRandom<T>(T[] array)
        {
            return array[r.Next(array.Length)];
        }
        #endregion
    }

    public class Product : Notifier
    {
        private string title;

        public string Title
        {
            get { return title; }
            set
            {
                title = value;
                OnPropertyChanged("Title");
            }
        }

        private decimal price;

        public decimal Price
        {
            get { return price; }
            set
            {
                price = value;
                OnPropertyChanged("Price");
            }
        }

        private string color;

        public string Color
        {
            get { return color; }
            set
            {
                color = value;
                OnPropertyChanged("Color");
            }
        }

        private string reference;

        public string Reference
        {
            get { return reference; }
            set
            {
                reference = value;
                OnPropertyChanged("Reference");
            }
        }

    }
}

==> learnwpfexercises/BikeShop/BikeShop/ProductsManagement.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace BikeShop
{
    /// <summary>
    /// Interaction logic for ProductsManagement.xaml
    /// </summary>
    public partial class ProductsManagement : Page
    {
        ProductsFactory factory = new ProductsFactory();
        public ProductsManagement()
        {
            InitializeComponent();
        }

        private void textBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            dataGrid.ItemsSource =
                factory.FindProducts(textBox.Text);
        }
    }
}

==> learnwpfexercises/BikeShop/BikeShop/ProductsManagementMVVM.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace BikeShop
{
    /// <summary>
    /// Interaction logic for ProductsManagementMVVM.xaml
    /// </summary>
    public partial class ProductsManagementMVVM : Page
    {
        public ProductsManagementMVVM()
        {
            InitializeComponent();
        }
    }
}

==> learnwpfexercises/BikeShop/BikeShop/ProductsManagementMVVMViewModel.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BikeShop
{
    public class ProductsManagementMVVMViewModel : Notifier
    {
        #region Input and output properties

        private string searchInput;

        public string SearchInput
        {
            get { return searchInput; }
            set
            {
                searchInput = value;
                base.OnPropertyChanged("SearchInput");
                OnSearchInputChanged();
            }
        }

        private IEnumerable<Product> foundProducts;

        public IEnumerable<Product> FoundProducts
        {
            get { return foundProducts; }
            set
            {
                foundProducts = value;
                OnPropertyChanged("FoundProducts");
            }
        }


        private Product selectedProduct;

        public Product SelectedProduct
        {
            get { return selectedProduct; }
            set
            {
                selectedProduct = value;
                OnPropertyChanged("SelectedProduct");
            }
        }

        #endregion

        ProductsFactory factory = new ProductsFactory();

        public ProductsManagementMVVMViewModel()
        {
            // Optional: we're just making sure the
            // list is empty.
            FoundProducts = Enumerable.Empty<Product>();
        }

        private void OnSearchInputChanged()
        {
            // Optional: just make sure any selected
            // product is unselected
            SelectedProduct = null;

            FoundProducts = factory.FindProducts(SearchInput);
        }
    }
}

==> learnwpfexercises/BikeShop/BikeShop/Properties/AssemblyInfo.cs <==
﻿using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Windows;

// General Information about an assembly is controlled through the following 
// set of attributes. Change these attribute values to modify the information
// associated with an assembly.
[assembly: AssemblyTitle("BikeShop")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("")]
[assembly: AssemblyProduct("BikeShop")]
[assembly: AssemblyCopyright("Copyright ©  2016")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyCulture("")]

// Setting ComVisible to false makes the types in this assembly not visible 
// to COM components.  If you need to access a type in this assembly from 
// COM, set the ComVisible attribute to true on that type.
[assembly: ComVisible(false)]

//In order to begin building localizable applications, set 
//<UICulture>CultureYouAreCodingWith</UICulture> in your .csproj file
//inside a <PropertyGroup>.  For example, if you are using US english
//in your source files, set the <UICulture> to en-US.  Then uncomment
//the NeutralResourceLanguage attribute below.  Update the "en-US" in
//the line below to match the UICulture setting in the project file.

//[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]


[assembly: ThemeInfo(
    ResourceDictionaryLocation.None, //where theme specific resource dictionaries are located
                                     //(used if a resource is not found in the page, 
                                     // or application resource dictionaries)
    ResourceDictionaryLocation.SourceAssembly //where the generic resource dictionary is located
                                              //(used if a resource is not found in the page, 
                                              // app, or any theme specific resource dictionaries)
)]


// Version information for an assembly consists of the following four values:
//
//      Major Version
//      Minor Version 
//      Build Number
//      Revision
//
// You can specify all the values or you can default the Build and Revision Numbers 
// by using the '*' as shown below:
// [assembly: AssemblyVersion("1.0.*")]
[assembly: AssemblyVersion("1.0.0.0")]
[assembly: AssemblyFileVersion("1.0.0.0")]

==> learnwpfexercises/BikeShop/BikeShop/Properties/Resources.Designer.cs <==
﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace BikeShop.Properties
{


    /// <summary>
    ///   A strongly-typed resource class, for looking up localized strings, etc.
    /// </summary>
    // This class was auto-generated by the StronglyTypedResourceBuilder
    // class via a tool like ResGen or Visual Studio.
    // To add or remove a member, edit your .ResX file then rerun ResGen
    // with the /str option, or rebuild your VS project.
    [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Resources.Tools.StronglyTypedResourceBuilder", "4.0.0.0")]
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
    [global::System.Runtime.CompilerServices.CompilerGeneratedAttribute()]
    internal class Resources
    {

        private static global::System.Resources.ResourceManager resourceMan;

        private static global::System.Globalization.CultureInfo resourceCulture;

        [global::System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1811:AvoidUncalledPrivateCode")]
        internal Resources()
        {
        }

        /// <summary>
        ///   Returns the cached ResourceManager instance used by this class.
        /// </summary>
        [global::System.ComponentModel.EditorBrowsableAttribute(global::System.ComponentModel.EditorBrowsableState.Advanced)]
        internal static global::System.Resources.ResourceManager ResourceManager
        {
            get
            {
                if ((resourceMan == null))
                {
                    global::System.Resources.ResourceManager temp = new global::System.Resources.ResourceManager("BikeShop.Properties.Resources", typeof(Resources).Assembly);
                    resourceMan = temp;
                }
                return resourceMan;
            }
        }

        /// <summary>
        ///   Overrides the current thread's CurrentUICulture property for all
        ///   resource lookups using this strongly typed resource class.
        /// </summary>
        [global::System.ComponentModel.EditorBrowsableAttribute(global::System.ComponentModel.EditorBrowsableState.Advanced)]
        internal static global::System.Globalization.CultureInfo Culture
        {
            get
            {
                return resourceCulture;
            }
            set
            {
                resourceCulture = value;
            }
        }
    }
}

==> learnwpfexercises/BikeShop/BikeShop/Properties/Settings.Designer.cs <==
﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace BikeShop.Properties
{


    [global::System.Runtime.CompilerServices.CompilerGeneratedAttribute()]
    [global::System.CodeDom.Compiler.GeneratedCodeAttribute("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "11.0.0.0")]
    internal sealed partial class Settings : global::System.Configuration.ApplicationSettingsBase
    {

        private static Settings defaultInstance = ((Settings)(global::System.Configuration.ApplicationSettingsBase.Synchronized(new Settings())));

        public static Settings Default
        {
            get
            {
                return defaultInstance;
            }
        }
    }
}

==> learnwpfexercises/BikeShop/BikeShop/Talk.cs <==
﻿using System;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;
using System.Collections.ObjectModel;

namespace BikeShop
{
    public class Talk : ObservableCollection<Message>
    {
        public Talk()
        {
            this.Add(new Message() { Sender = "Adventure Works", Content = "Hi, what can we do for you?" });
            this.Add(new Message() { Sender = "Client", Content = "Did you receive the GR268 KZ bike?" });
            this.Add(new Message() { Sender = "Adventure Works", Content = "Not yet, but we have a similar model available." });
            this.Add(new Message() { Sender = "Client", Content = "What is it like?" });
            this.Add(new Message() { Sender = "Adventure Works", Content = "It boasts a carbon frame, hydraulic brakes and suspension, and a gear hub." });
            this.Add(new Message() { Sender = "Client", Content = "How much does it cost?" });
            this.Add(new Message() { Sender = "Adventure Works", Content = "Same as the GR268 KZ model you requested. You can get it from our online shop." });
            this.Add(new Message() { Sender = "Client", Content = "Thanks." });
            this.Add(new Message() { Sender = "Adventure Works", Content = "Thank you, have a nice ride." });
        }
    }

    public class Message
    {
        public string Sender { get; set; }
        public string Content { get; set; }
    }
}

==> learnwpfexercises/StartAssets/Notifier.cs <==
﻿using System.ComponentModel;

public class Notifier : INotifyPropertyChanged
{
    public event PropertyChangedEventHandler PropertyChanged;

    protected void OnPropertyChanged(string propertyName)
    {
        if (PropertyChanged != null)
        {
            PropertyChanged(this,
                new PropertyChangedEventArgs(propertyName));
        }
    }
}

==> learnwpfexercises/StartAssets/ProductsFactory.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BikeShop
{
    public class ProductsFactory
    {
        public IEnumerable<Product> GetAllProducts()
        {
            return products;
        }

        public IEnumerable<Product> FindProducts(string searchString)
        {
            return products.Where(p => p.Title.Contains(searchString));
        }

        #region In-memory data
        // This code builds an in-memory product collection
        // but we could as well fectch it from a database
        // or web service and it would yield the same result.
        static IList<Product> products;
        static ProductsFactory()
        {
            products = new List<Product>();
            for (int i = 0; i < 100; i++)
            {
                products.Add(generateRandomProduct());
            }
        }

        static Random r = new Random(DateTime.Now.Millisecond);
        static Product generateRandomProduct()
        {
            var titles = new string[] { "Classic city bike", "Vintage city bike", "Basic mountain bike", "Easy mountain bike", "Devil mountain bike" };
            var colors = new string[] { "Red", "Blue", "Green", "Brown", "Gray", "Black" };
            return new Product()
            {
                Title = pickRandom(titles),
                Color = pickRandom(colors),
                Price = Math.Round(300M + (decimal)r.NextDouble() * 1700M, 2),
                Reference = "BK"+r.Next(100000).ToString("d8")
            };
        }
        static T pickRandom<T>(T[] array)
        {
            return array[r.Next(array.Length)];
        }
        #endregion
    }

    public class Product : Notifier
    {
        private string title;

        public string Title
        {
            get { return title; }
            set
            {
                title = value;
                OnPropertyChanged("Title");
            }
        }

        private decimal price;

        public decimal Price
        {
            get { return price; }
            set
            {
                price = value;
                OnPropertyChanged("Price");
            }
        }

        private string color;

        public string Color
        {
            get { return color; }
            set
            {
                color = value;
                OnPropertyChanged("Color");
            }
        }

        private string reference;

        public string Reference
        {
            get { return reference; }
            set
            {
                reference = value;
                OnPropertyChanged("Reference");
            }
        }

    }
}

==> learnwpfexercises/StartAssets/RelayCommand.cs <==
﻿using System;
using System.Windows.Input;
using System.Diagnostics;

// Source: http://blog.walteralmeida.com/2010/06/modelviewviewmodel-design-pattern-an-implementation-of-relaycommand-for-silverlight.html
//Relay Command class for WPF.
/*
   This class makes use of the CommandManager object and the RequerySuggested event. 
   When a user actions the UI in WPF, this triggers the CommandManager to requery all the commands.
*/

public class RelayCommand : ICommand
{

    #region Fields

    readonly Action<object> _execute;
    readonly Predicate<object> _canExecute;

    #endregion // Fields

    #region Constructors

    public RelayCommand(Action<object> execute)
        : this(execute, null)
    {
    }

    public RelayCommand(Action<object> execute, Predicate<object> canExecute)
    {
        if (execute == null)
            throw new ArgumentNullException("execute");

        _execute = execute;
        _canExecute = canExecute;
    }

    #endregion // Constructors

    #region ICommand Members

    [DebuggerStepThrough]
    public bool CanExecute(object parameter)
    {
        return _canExecute == null ? true : _canExecute(parameter);
    }

    public event EventHandler CanExecuteChanged
    {
        add { CommandManager.RequerySuggested += value; }
        remove { CommandManager.RequerySuggested -= value; }
    }

    public void Execute(object parameter)
    {
        _execute(parameter);
    }

    #endregion // ICommand Members
}


==> learnwpfexercises/StartAssets/Talk.cs <==
﻿using System;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;
using System.Collections.ObjectModel;

namespace BikeShop
{
    public class Talk : ObservableCollection<Message>
    {
        public Talk()
        {
            this.Add(new Message() { Sender = "Adventure Works", Content = "Hi, what can we do for you?" });
            this.Add(new Message() { Sender = "Client", Content = "Did you receive the GR268 KZ bike?" });
            this.Add(new Message() { Sender = "Adventure Works", Content = "Not yet, but we have a similar model available." });
            this.Add(new Message() { Sender = "Client", Content = "What is it like?" });
            this.Add(new Message() { Sender = "Adventure Works", Content = "It boasts a carbon frame, hydraulic brakes and suspension, and a gear hub." });
            this.Add(new Message() { Sender = "Client", Content = "How much does it cost?" });
            this.Add(new Message() { Sender = "Adventure Works", Content = "Same as the GR268 KZ model you requested. You can get it from our online shop." });
            this.Add(new Message() { Sender = "Client", Content = "Thanks." });
            this.Add(new Message() { Sender = "Adventure Works", Content = "Thank you, have a nice ride." });
        }
    }

    public class Message
    {
        public string Sender { get; set; }
        public string Content { get; set; }
    }
}

==> learnwpfexercises/WpfDemos/WpfDemos/App.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace WpfDemos
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
    }
}

==> learnwpfexercises/WpfDemos/WpfDemos/Car.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;

namespace BusinessLogic
{
    public class Human
    {
        public string FirstName { get; set; }
        public bool HasDrivingLicense { get; set; }
    }

    public class Car : Notifier
    {
        private double speed;

        public double Speed
        {
            get { return speed; }
            set
            {
                speed = value;
                OnPropertyChanged("Speed");
            }
        }

        public Color Color { get; set; }
        public Human Driver { get; set; }
    }
}

==> learnwpfexercises/WpfDemos/WpfDemos/CollectionOfCars.xaml.cs <==
﻿using BusinessLogic;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfDemos
{
    /// <summary>
    /// Interaction logic for CollectionOfCars.xaml
    /// </summary>
    public partial class CollectionOfCars : Page
    {
        public CollectionOfCars()
        {
            InitializeComponent();

            var cars = new List<Car>();
            for (int i = 0; i < 10; i++)
            {
                cars.Add(new Car() {
                    Speed = i * 10,
                    Color = Colors.Red
                });
            }
            this.DataContext = cars;
        }
    }
}

==> learnwpfexercises/WpfDemos/WpfDemos/CurrencyConverter.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace WpfDemos
{
    /// <summary>
    /// Interaction logic for CurrencyConverter.xaml
    /// </summary>
    public partial class CurrencyConverter : Page
    {
        public CurrencyConverter()
        {
            InitializeComponent();
        }
    }
}

==> learnwpfexercises/WpfDemos/WpfDemos/CurrencyConverter2.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfDemos
{
    /// <summary>
    /// Interaction logic for CurrencyConverter2.xaml
    /// </summary>
    public partial class CurrencyConverter2 : Page
    {
        public CurrencyConverter2()
        {
            InitializeComponent();
        }
    }
}

==> learnwpfexercises/WpfDemos/WpfDemos/CurrencyConverterViewModel.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WpfDemos
{
    public class CurrencyConverterViewModel : Notifier
    {
        // Verbose code we can almost ignore
        private decimal euros;

        public decimal Euros
        {
            get { return euros; }
            set
            {
                euros = value;
                OnPropertyChanged("Euros");
                OnEurosChanged();
            }
        }

        private decimal dollars;

        public decimal Dollars
        {
            get { return dollars; }
            set
            {
                dollars = value;
                OnPropertyChanged("Dollars");
            }
        }

        // This is where the magic hapens
        private void OnEurosChanged()
        {
            Dollars = Euros * 1.1M;
        }
    }
}

==> learnwpfexercises/WpfDemos/WpfDemos/CurrencyConverterViewModel2.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WpfDemos
{
    public class Currency
    {
        public Currency(string title, decimal rate)
        {
            Title = title;
            Rate = rate;
        }
        public string Title { get; set; }
        public decimal Rate { get; set; }
    }

    public class CurrencyConverterViewModel2 : Notifier
    {
        // Verbose code we can almost ignore
        private decimal euros;

        public decimal Euros
        {
            get { return euros; }
            set
            {
                euros = value;
                OnPropertyChanged("Euros");
                OnEurosChanged();
            }
        }

        private decimal converted;

        public decimal Converted
        {
            get { return converted; }
            set
            {
                converted = value;
                OnPropertyChanged("Converted");
            }
        }

        private Currency selectedCurrency;

        public Currency SelectedCurrency
        {
            get { return selectedCurrency; }
            set { selectedCurrency = value;
                OnPropertyChanged("SelectedCurrency");
                OnSelectedCurrencyChanged();
            }
        }

        private IEnumerable<Currency> currencies;

        public IEnumerable<Currency> Currencies
        {
            get { return currencies; }
            set { currencies = value;
                OnPropertyChanged("Currencies");
            }
        }

        private string resultText;

        public string ResultText
        {
            get { return resultText; }
            set { resultText = value;
                OnPropertyChanged("ResultText");
            }
        }


        // This is where the magic hapens
        public CurrencyConverterViewModel2()
        {
            Currencies = new Currency[] {
                new Currency("US Dollar", 1.1M),
                new Currency("British Pound", 0.9M),
            };
        }

        private void OnEurosChanged()
        {
            ComputeConverted();
        }
        private void OnSelectedCurrencyChanged()
        {
            ComputeConverted();
        }

        private void ComputeConverted()
        {
            if (SelectedCurrency == null)
            {
                return;
            }
            Converted = Euros * SelectedCurrency.Rate;
            ResultText = string.Format(
                "Amount in {0}", SelectedCurrency.Title);
        }
    }
}

==> learnwpfexercises/WpfDemos/WpfDemos/LayoutVsRender.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfDemos
{
    /// <summary>
    /// Interaction logic for LayoutVsRender.xaml
    /// </summary>
    public partial class LayoutVsRender : Page
    {
        public LayoutVsRender()
        {
            InitializeComponent();
        }
    }
}

==> learnwpfexercises/WpfDemos/WpfDemos/MainWindow.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfDemos
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
    }
}

==> learnwpfexercises/WpfDemos/WpfDemos/Notifier.cs <==
﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Notifier : INotifyPropertyChanged
{
    public event PropertyChangedEventHandler PropertyChanged;

    protected void OnPropertyChanged(string propertyName)
    {
        if(PropertyChanged!=null)
        {
            PropertyChanged(this,
                new PropertyChangedEventArgs(propertyName));
        }
    }
}

==> learnwpfexercises/WpfDemos/WpfDemos/Properties/AssemblyInfo.cs <==
﻿using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Windows;

// General Information about an assembly is controlled through the following 
// set of attributes. Change these attribute values to modify the information
// associated with an assembly.
[assembly: AssemblyTitle("WpfDemos")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("")]
[assembly: AssemblyProduct("WpfDemos")]
[assembly: AssemblyCopyright("Copyright ©  2016")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyCulture("")]

// Setting ComVisible to false makes the types in this assembly not visible 
// to COM components.  If you need to access a type in this assembly from 
// COM, set the ComVisible attribute to true on that type.
[assembly: ComVisible(false)]

//In order to begin building localizable applications, set 
//<UICulture>CultureYouAreCodingWith</UICulture> in your .csproj file
//inside a <PropertyGroup>.  For example, if you are using US english
//in your source files, set the <UICulture> to en-US.  Then uncomment
//the NeutralResourceLanguage attribute below.  Update the "en-US" in
//the line below to match the UICulture setting in the project file.

//[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]


[assembly: ThemeInfo(
    ResourceDictionaryLocation.None, //where theme specific resource dictionaries are located
                                     //(used if a resource is not found in the page, 
                                     // or application resource dictionaries)
    ResourceDictionaryLocation.SourceAssembly //where the generic resource dictionary is located
                                              //(used if a resource is not found in the page, 
                                              // app, or any theme specific resource dictionaries)
)]


// Version information for an assembly consists of the following four values:
//
//      Major Version
//      Minor Version 
//      Build Number
//      Revision
//
// You can specify all the values or you can default the Build and Revision Numbers 
// by using the '*' as shown below:
// [assembly: AssemblyVersion("1.0.*")]
[assembly: AssemblyVersion("1.0.0.0")]
[assembly: AssemblyFileVersion("1.0.0.0")]

==> learnwpfexercises/WpfDemos/WpfDemos/Properties/Resources.Designer.cs <==
﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace WpfDemos.Properties
{


    /// <summary>
    ///   A strongly-typed resource class, for looking up localized strings, etc.
    /// </summary>
    // This class was auto-generated by the StronglyTypedResourceBuilder
    // class via a tool like ResGen or Visual Studio.
    // To add or remove a member, edit your .ResX file then rerun ResGen
    // with the /str option, or rebuild your VS project.
    [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Resources.Tools.StronglyTypedResourceBuilder", "4.0.0.0")]
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
    [global::System.Runtime.CompilerServices.CompilerGeneratedAttribute()]
    internal class Resources
    {

        private static global::System.Resources.ResourceManager resourceMan;

        private static global::System.Globalization.CultureInfo resourceCulture;

        [global::System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1811:AvoidUncalledPrivateCode")]
        internal Resources()
        {
        }

        /// <summary>
        ///   Returns the cached ResourceManager instance used by this class.
        /// </summary>
        [global::System.ComponentModel.EditorBrowsableAttribute(global::System.ComponentModel.EditorBrowsableState.Advanced)]
        internal static global::System.Resources.ResourceManager ResourceManager
        {
            get
            {
                if ((resourceMan == null))
                {
                    global::System.Resources.ResourceManager temp = new global::System.Resources.ResourceManager("WpfDemos.Properties.Resources", typeof(Resources).Assembly);
                    resourceMan = temp;
                }
                return resourceMan;
            }
        }

        /// <summary>
        ///   Overrides the current thread's CurrentUICulture property for all
        ///   resource lookups using this strongly typed resource class.
        /// </summary>
        [global::System.ComponentModel.EditorBrowsableAttribute(global::System.ComponentModel.EditorBrowsableState.Advanced)]
        internal static global::System.Globalization.CultureInfo Culture
        {
            get
            {
                return resourceCulture;
            }
            set
            {
                resourceCulture = value;
            }
        }
    }
}

==> learnwpfexercises/WpfDemos/WpfDemos/Properties/Settings.Designer.cs <==
﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace WpfDemos.Properties
{


    [global::System.Runtime.CompilerServices.CompilerGeneratedAttribute()]
    [global::System.CodeDom.Compiler.GeneratedCodeAttribute("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "11.0.0.0")]
    internal sealed partial class Settings : global::System.Configuration.ApplicationSettingsBase
    {

        private static Settings defaultInstance = ((Settings)(global::System.Configuration.ApplicationSettingsBase.Synchronized(new Settings())));

        public static Settings Default
        {
            get
            {
                return defaultInstance;
            }
        }
    }
}

==> learnwpfexercises/WpfDemos/WpfDemos/SelectionControls.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfDemos
{
    /// <summary>
    /// Interaction logic for SelectionControls.xaml
    /// </summary>
    public partial class SelectionControls : Page
    {
        public SelectionControls()
        {
            InitializeComponent();
        }
    }
}

==> learnwpfexercises/WpfDemos/WpfDemos/Sizing.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace WpfDemos
{
    /// <summary>
    /// Interaction logic for Sizing.xaml
    /// </summary>
    public partial class Sizing : Window
    {
        public Sizing()
        {
            InitializeComponent();
        }
    }
}

==> learnwpfexercises/WpfDemos/WpfDemos/Styling.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfDemos
{
    /// <summary>
    /// Interaction logic for Styling.xaml
    /// </summary>
    public partial class Styling : Page
    {
        public Styling()
        {
            InitializeComponent();
        }
    }
}

==> learnwpfexercises/WpfDemos/WpfDemos/Templating.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfDemos
{
    /// <summary>
    /// Interaction logic for Templating.xaml
    /// </summary>
    public partial class Templating : Page
    {
        public Templating()
        {
            InitializeComponent();
        }
    }
}
==> source/repos/BikeShop/BikeShop/App.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace BikeShop
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
    }
}

==> source/repos/BikeShop/BikeShop/AssemblyInfo.cs <==
using System.Windows;

[assembly: ThemeInfo(
    ResourceDictionaryLocation.None, //where theme specific resource dictionaries are located
                                     //(used if a resource is not found in the page,
                                     // or application resource dictionaries)
    ResourceDictionaryLocation.SourceAssembly //where the generic resource dictionary is located
                                              //(used if a resource is not found in the page,
                                              // app, or any theme specific resource dictionaries)
)]

==> source/repos/BikeShop/BikeShop/Contact.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace BikeShop
{
    /// <summary>
    /// Interaction logic for Contact.xaml
    /// </summary>
    public partial class Contact : Page
    {
        public Contact()
        {
            InitializeComponent();
        }
    }
}

==> source/repos/BikeShop/BikeShop/Discussion.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace BikeShop
{
    /// <summary>
    /// Interaction logic for Discussion.xaml
    /// </summary>
    public partial class Discussion : Page
    {
        public Discussion()
        {
            InitializeComponent();
        }
    }
}

==> source/repos/BikeShop/BikeShop/MainWindow.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace BikeShop
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window

    {
        public MainWindow()
        {
            InitializeComponent(); 
        }
    }
}

==> source/repos/BikeShop/BikeShop/Menu.xaml.cs <==
﻿using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;

namespace BikeShop
{
    /// <summary>
    /// Interaction logic for Menu.xaml
    /// </summary>
    public partial class Menu : Page
    {
        public Menu()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(
                new Uri("/Contact.xaml", UriKind.Relative)
            );
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(
                new Uri("/Discussion.xaml", UriKind.Relative)
            );
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(
                new Uri("/ProductsManagement.xaml", UriKind.Relative)
            );
        }
    }
}

==> source/repos/BikeShop/BikeShop/Notifier.cs <==
﻿using System.ComponentModel;

public class Notifier : INotifyPropertyChanged
{
    public event PropertyChangedEventHandler PropertyChanged;

    protected void OnPropertyChanged(string propertyName)
    {
        if (PropertyChanged != null)
        {
            PropertyChanged(this,
                new PropertyChangedEventArgs(propertyName));
        }
    }
}

==> source/repos/BikeShop/BikeShop/ProductsFactory.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BikeShop
{
    public class ProductsFactory
    {
        public IEnumerable<Product> GetAllProducts()
        {
            return products;
        }

        public IEnumerable<Product> FindProducts(string searchString)
        {
            return products.Where(p => p.Title.Contains(searchString));
        }

        #region In-memory data
        // This code builds an in-memory product collection
        // but we could as well fectch it from a database
        // or web service and it would yield the same result.
        static IList<Product> products;
        static ProductsFactory()
        {
            products = new List<Product>();
            for (int i = 0; i < 100; i++)
            {
                products.Add(generateRandomProduct());
            }
        }

        static Random r = new Random(DateTime.Now.Millisecond);
        static Product generateRandomProduct()
        {
            var titles = new string[] { "Classic city bike", "Vintage city bike", "Basic mountain bike", "Easy mountain bike", "Devil mountain bike" };
            var colors = new string[] { "Red", "Blue", "Green", "Brown", "Gray", "Black" };
            return new Product()
            {
                Title = pickRandom(titles),
                Color = pickRandom(colors),
                Price = Math.Round(300M + (decimal)r.NextDouble() * 1700M, 2),
                Reference = "BK"+r.Next(100000).ToString("d8")
            };
        }
        static T pickRandom<T>(T[] array)
        {
            return array[r.Next(array.Length)];
        }
        #endregion
    }

    public class Product : Notifier
    {
        private string title;

        public string Title
        {
            get { return title; }
            set
            {
                title = value;
                OnPropertyChanged("Title");
            }
        }

        private decimal price;

        public decimal Price
        {
            get { return price; }
            set
            {
                price = value;
                OnPropertyChanged("Price");
            }
        }

        private string color;

        public string Color
        {
            get { return color; }
            set
            {
                color = value;
                OnPropertyChanged("Color");
            }
        }

        private string reference;

        public string Reference
        {
            get { return reference; }
            set
            {
                reference = value;
                OnPropertyChanged("Reference");
            }
        }

    }
}

==> source/repos/BikeShop/BikeShop/ProductsManagement.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace BikeShop
{
    /// <summary>
    /// Interaction logic for ProductsManagement.xaml
    /// </summary>
    public partial class ProductsManagement : Page
    {
        ProductsFactory factory = new ProductsFactory();

        public ProductsManagement()
        {
            InitializeComponent();
        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            dataGrid.ItemsSource = factory.FindProducts(textBox.Text);
        }
    }
}

==> source/repos/BikeShop/BikeShop/Talk.cs <==
﻿using System;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;
using System.Collections.ObjectModel;

namespace BikeShop
{
    public class Talk : ObservableCollection<Message>
    {
        public Talk()
        {
            this.Add(new Message() { Sender = "Adventure Works", Content = "Hi, what can we do for you?" });
            this.Add(new Message() { Sender = "Client", Content = "Did you receive the GR268 KZ bike?" });
            this.Add(new Message() { Sender = "Adventure Works", Content = "Not yet, but we have a similar model available." });
            this.Add(new Message() { Sender = "Client", Content = "What is it like?" });
            this.Add(new Message() { Sender = "Adventure Works", Content = "It boasts a carbon frame, hydraulic brakes and suspension, and a gear hub." });
            this.Add(new Message() { Sender = "Client", Content = "How much does it cost?" });
            this.Add(new Message() { Sender = "Adventure Works", Content = "Same as the GR268 KZ model you requested. You can get it from our online shop." });
            this.Add(new Message() { Sender = "Client", Content = "Thanks." });
            this.Add(new Message() { Sender = "Adventure Works", Content = "Thank you, have a nice ride." });
        }
    }

    public class Message
    {
        public string Sender { get; set; }
        public string Content { get; set; }
    }
}

==> source/repos/CurrencyConverter/CurrencyConverter/App.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace CurrencyConverter
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
    }
}

==> source/repos/CurrencyConverter/CurrencyConverter/AssemblyInfo.cs <==
using System.Windows;

[assembly: ThemeInfo(
    ResourceDictionaryLocation.None, //where theme specific resource dictionaries are located
                                     //(used if a resource is not found in the page,
                                     // or application resource dictionaries)
    ResourceDictionaryLocation.SourceAssembly //where the generic resource dictionary is located
                                              //(used if a resource is not found in the page,
                                              // app, or any theme specific resource dictionaries)
)]

==> source/repos/CurrencyConverter/CurrencyConverter/CurrencyConverterModel.cs <==
﻿using System;
using System.Collections.Generic;
using System.Text;

namespace CurrencyConverter
{
    public class CurrencyConverterModel
    {
        private CurrencyConverterViewModel _thisConverterModel;

        public CurrencyConverterModel(CurrencyConverterViewModel converterModel)
        {
            _thisConverterModel = converterModel;
        }
        
        public decimal OnEurosChanged()
        {
            _thisConverterModel._Dollars = _thisConverterModel._Euros * 1.1M;
            return _thisConverterModel._Dollars;
        }
    }
}

==> source/repos/CurrencyConverter/CurrencyConverter/CurrencyConverterViewModel.cs <==
﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Text;

namespace CurrencyConverter
{
    public class CurrencyConverterViewModel : Notifier
    {
        private CurrencyConverterModel newModel;

        private decimal _dollars;
        public decimal _Dollars
        {
            get { return _dollars; }
            set
            {
                _dollars = value;
                OnPropertyChanged("_Dollars");
            }
        }

        private decimal _euros;
        public decimal _Euros
        {
            get { return _euros; }
            set
            {
                _euros = value; 
                OnPropertyChanged("_Euros");
                newModel = new CurrencyConverterModel(this);
                _Dollars = newModel.OnEurosChanged();
                //OnEurosChanged();
            }
        }

        /*private void OnEurosChanged()
        {
            _Dollars = _Euros * 1.1M;
        }*/
    }

    public class Notifier : INotifyPropertyChanged
    { 
        public event PropertyChangedEventHandler PropertyChanged;
                     
        protected void OnPropertyChanged(string propertyName)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }
    }
}
                            
==> source/repos/CurrencyConverter/CurrencyConverter/MainWindow.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace CurrencyConverter
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            this.DataContext = new CurrencyConverterViewModel();
        }
    }
}

==> source/repos/CurrencyConverter2/CurrencyConverter2/App.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace CurrencyConverter2
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
    }
}

==> source/repos/CurrencyConverter2/CurrencyConverter2/AssemblyInfo.cs <==
using System.Windows;

[assembly: ThemeInfo(
    ResourceDictionaryLocation.None, //where theme specific resource dictionaries are located
                                     //(used if a resource is not found in the page,
                                     // or application resource dictionaries)
    ResourceDictionaryLocation.SourceAssembly //where the generic resource dictionary is located
                                              //(used if a resource is not found in the page,
                                              // app, or any theme specific resource dictionaries)
)]

==> source/repos/CurrencyConverter2/CurrencyConverter2/Currency.cs <==
﻿using System;
using System.Collections.Generic;
using System.Text;

namespace CurrencyConverter2
{
    class Currency
    {
        public string _Title { get; set; }
        public decimal _Rate { get; set; }

        public Currency(string title, decimal rate)
        {
            _Title = title;
            _Rate = rate;
        }
    }
}
==> source/repos/CurrencyConverter2/CurrencyConverter2/CurrencyConverterViewModel.cs <==
﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Text;

namespace CurrencyConverter2
{
    public class Notifier : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        protected void OnPropertyChanged(string propertyName)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }
    }

    class CurrencyConverterViewModel : Notifier
    {
        private decimal _euros;

        public decimal _Euros
        {
            get { return _euros; }
            set
            {
                _euros = value;
                OnEurosChanged();
                OnPropertyChanged("_Euros");
            }
        }

        private decimal _converted;

        public decimal _Converted
        {
            get { return _converted; }
            set
            {
                _converted = value;
                OnPropertyChanged("_Converted");
            }
        }

        private Currency _selectedCurrency;

        public Currency _SelectedCurrency
        {
            get { return _selectedCurrency; }
            set
            {
                OnSelectedCurrencyChanged();
                OnPropertyChanged("_SelectedCurrency");
            }
        }

        private IEnumerable<Currency> _currencies;

        public IEnumerable<Currency> _Currencies
        {
            get { return _currencies; }
            set
            {
                _currencies = value;
                OnPropertyChanged("_Currencies");
            }
        }

        private string _resultText;

        public string _ResultText
        {
            get { return _resultText; }
            set
            {
                _resultText = value;
                OnPropertyChanged("_ResultText");
            }
        }

        public CurrencyConverterViewModel()
        {
            _Currencies = new Currency[]
            {
                new Currency("US Dollar", 1.1M),
                new Currency("British Pound", 0.9M),
            };
        }

        private void ComputeConverted()
        {
            if (_SelectedCurrency == null)
            {
                return;
            }
            _Converted = _Euros * _SelectedCurrency._Rate;
            _ResultText = string.Format("Amount in {0}", _SelectedCurrency._Title);
        }

        private void OnEurosChanged()
        {
            ComputeConverted();
        }

        private void OnSelectedCurrencyChanged()
        {
            ComputeConverted();
        }
    }
}

==> source/repos/CurrencyConverter2/CurrencyConverter2/MainWindow.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace CurrencyConverter2
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
    }
}

==> source/repos/Eventhandlers.cs <==
==> ./Observer_pattern1/Observer_pattern1/Program.cs <==
using System;
using System.Collections.Generic;

namespace Observer_pattern1
{
    public class Args
    {
    }

    public abstract class ASubject
    {
        protected List<IObserver> observersList = new List<IObserver>();

        public void AddObserver(IObserver observer)
        {
            observersList.Add(observer);
        }

        public void RemoveObserver(IObserver observer)
        {
            observersList.Remove(observer);
        }
    }

    public interface IObserver
    {
        void Update(object subject, Args args);
    }

    public class Subject : ASubject
    {
        public string SubjectState = null;

        public void NotifyObservers()
        {
            ArgsSubject args = new ArgsSubject();
            args.SubjectState = this.SubjectState;

            foreach (IObserver o in observersList)
            {
                o.Update(this, args);
            }
        }
    }

    public class Observer : IObserver
    {
        private string name;
        private string observerState;

        public Observer(string name)
        {
            this.name = name;
        }

        public void Update(object s, Args args)
        {
            observerState = ((ArgsSubject)args).SubjectState;
            Console.WriteLine("Observer {0}'s new state is {1}",
                name, observerState);
        }
    }

    public class ArgsSubject : Args
    {
        public string SubjectState = null;
    }

    class Client
    {
        static void Main(string[] args)
        {
            Subject s = new Subject();
            s.AddObserver(new Observer("1"));
            s.AddObserver(new Observer("2"));
            s.AddObserver(new Observer("3"));

            // Change subject state and notify observers
            s.SubjectState = "ABC123";
            s.NotifyObservers();

            Console.ReadLine();
        }
    }
}

==> ./Observer_pattern2/Observer_pattern2/Program.cs <==
using System;
using System.IO.IsolatedStorage;

namespace Observer_pattern2
{
    public class Subject
    {
        public event EventHandler<EventArgsSubject> SubjectEvent;

        public string SubjectState;

        public void NotifyObservers()
        {
            EventArgsSubject args = new EventArgsSubject();
            args.SubjectState = this.SubjectState;

            // (1)
            if (SubjectEvent != null)
            {
                SubjectEvent(this, args);
            }
        }
    }

    public class Observer
    {
        private string name;
        private string observerState;

        public Observer(string name)
        {
            this.name = name;
        }

        public void Update(object subject, EventArgsSubject args)
        {
            observerState = args.SubjectState;
            Console.WriteLine("Observer {0}'s new state is {1}",
                name, observerState);
        }
    }

    public class EventArgsSubject : EventArgs
    {
        public string SubjectState = null;
    }

    class Client
    {
        static void Main(string[] args)
        {
            Subject s = new Subject();
            s.SubjectEvent += (new Observer("1")).Update;
            s.SubjectEvent += (new Observer("2")).Update;
            s.SubjectEvent += (new Observer("3")).Update;

            s.SubjectState = "ABC123";
            s.NotifyObservers();

            Console.ReadLine();
        }
    }
}

==> ./Observer_pattern3/Observer_pattern3/Program.cs <==
using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Threading;

namespace Observer_pattern3
{
    public class EventArgsW : EventArgs
    {
        public string StateW = null;
    }

    public class EventWrapper
    {
        public event EventHandler<EventArgsW> EventW;

        public string StateW;

        public void Notify()
        {
            Console.WriteLine("Notify is running on ThreadId:{0}",
                Thread.CurrentThread.ManagedThreadId);

            EventArgsW args = new EventArgsW();
            args.StateW = this.StateW;

            EventW?.Invoke(this, args);
        }
    }

    public class HandlerWrapper
    {
        private string name;
        private string StateW;
        private ManualResetEvent mrs;

        public HandlerWrapper(string name, ManualResetEvent mrs)
        {
            this.name = name;
            this.mrs = mrs;
        }

        public void Handler(object subject, EventArgsW args)
        {
            Console.WriteLine("Handler{0} is running on ThreadId:{1}",
                name, Thread.CurrentThread.ManagedThreadId);

            Worker(subject, args);
        }

        private void Worker(object subject, EventArgsW args)
        {
            Console.WriteLine("Handler{0}.Worker is running on Threadid:{1}, i:0",
                name, Thread.CurrentThread.ManagedThreadId);
            StateW = args.StateW;

            for (int i = 1; i <= 2; ++i)
            {
                Thread.Sleep(5000);
                Console.WriteLine("Handler{0}.Worker is running on Threadid:{1}, i:0",
                    name, Thread.CurrentThread.ManagedThreadId);
            }

            mrs.Set();
        }
    }

    class Client
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Client is running on ThreadId:{0}",
                Thread.CurrentThread.ManagedThreadId);

            ManualResetEvent[] mres = new ManualResetEvent[3];
            for (int i = 0; i < mres.Length; i++) mres[i] = new ManualResetEvent(false);

            EventWrapper s = new EventWrapper();
            s.EventW += (new HandlerWrapper("1", mres[0])).Handler;
            s.EventW += (new HandlerWrapper("2", mres[1])).Handler;
            s.EventW += (new HandlerWrapper("3", mres[2])).Handler;

            // Change subject state and notify observers
            s.StateW = "ABC123";

            var timer = new Stopwatch();
            timer.Start();

            s.Notify();

            ManualResetEvent.WaitAll(mres);
            timer.Stop();
            TimeSpan timeTaken = timer.Elapsed;
            string tmp1 = "Client time taken: " + timeTaken.ToString(@"m\:ss\.fff");
            Console.WriteLine(tmp1);

            Console.ReadLine();
        }
    }
}

==> ./Observer_pattern4/Observer_pattern4/Program.cs <==
using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;

namespace Observer_pattern4
{
    public class EventArgsW : EventArgs
    {
        public string StateW = null;
    }

    public class EventWrapper
    {
        public event EventHandler<EventArgsW> EventW;

        public string StateW;

        public void Notify()
        {
            Task.Factory.StartNew(
                () => {
                    Console.WriteLine("Notify is running on ThreadId:{0}",
                        Thread.CurrentThread.ManagedThreadId);

                    EventArgsW args = new EventArgsW();
                    args.StateW = this.StateW;

                    EventW?.Invoke(this, args);
                });
        }
    }

    public class HandlerWrapper
    {
        private string name;
        private string StateW;
        private ManualResetEvent mrs;

        public HandlerWrapper(string name, ManualResetEvent mrs)
        {
            this.name = name;
            this.mrs = mrs;
        }

        public void Handler(object subject, EventArgsW args)
        {
            Console.WriteLine("Handler{0} is running on Threadid:{1}",
                name, Thread.CurrentThread.ManagedThreadId);

            Task.Factory.StartNew(
                () => Worker(subject, args));
        }

        private void Worker(object subject, EventArgsW args)
        {
            Console.WriteLine("Handler{0}.Worker is running on threadId:{1}, i:0",
                name, Thread.CurrentThread.ManagedThreadId);
            StateW = args.StateW;

            for (int i = 1; i <= 2; ++i)
            {
                Thread.Sleep(5000);
                Console.WriteLine("Handler{0}.Worker is running on ThreadId:{1}, i:{2}",
                    name, Thread.CurrentThread.ManagedThreadId, i);
            }
            mrs.Set();
        }
    }

    internal class Client
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Client is running on threadId:{0}",
                Thread.CurrentThread.ManagedThreadId);

            ManualResetEvent[] mres = new ManualResetEvent[3];
            for (int i = 0; i < mres.Length; i++) mres[i] = new ManualResetEvent(false);

            EventWrapper s = new EventWrapper();
            s.EventW += (new HandlerWrapper("1", mres[0])).Handler;
            s.EventW += (new HandlerWrapper("2", mres[1])).Handler;
            s.EventW += (new HandlerWrapper("3", mres[2])).Handler;

            // change subject state and notify observers
            s.StateW = "ABC123";

            var timer = new Stopwatch();
            timer.Start();

            s.Notify();

            ManualResetEvent.WaitAll(mres);
            timer.Stop();
            TimeSpan timeTaken = timer.Elapsed;
            string tmp1 = "Client time taken: " + timeTaken.ToString(@"m\:ss\.fff");
            Console.WriteLine(tmp1);

            Console.ReadLine();
        }
    }
}

==> ./Observer_pattern5/Observer_pattern5/Program.cs <==
using System;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;

namespace Observer_pattern5
{
    public class EventArgsW : EventArgs
    {
        public string StateW = null;
    }

    public class EventWrapper
    {
        public event EventHandler<EventArgsW> EventW;

        public string StateW;

        public void Notify()
        {
            Console.WriteLine("Notify is running on ThreadId:{0}",
                Thread.CurrentThread.ManagedThreadId);

            EventArgsW args = new EventArgsW();
            args.StateW = this.StateW;

            EventW?.InvokeAsync<EventArgsW>(this, args);
        }
    }

    public class HandlerWrapper
    {
        private string name;
        private string StateW;
        private ManualResetEvent mrs;

        public HandlerWrapper(string name, ManualResetEvent mrs)
        {
            this.name = name;
            this.mrs = mrs;
        }

        public void Handler(object subject, EventArgsW args)
        {
            Console.WriteLine("Handler{0} is running on Threadid:{1}",
                name, Thread.CurrentThread.ManagedThreadId);

            Worker(subject, args);
        }

        private void Worker(object subject, EventArgsW args)
        {
            Console.WriteLine("Handler{0}.Worker is running on ThreadId:{1}, i:0",
                name, Thread.CurrentThread.ManagedThreadId);
            StateW = args.StateW;

            for (int i = 1; i <= 2; ++i)
            {
                Thread.Sleep(5000);
                Console.WriteLine("Handler{0}.Worker is running on ThreadId:{1}, i:{2}",
                    name, Thread.CurrentThread.ManagedThreadId, i);
            }
        }
    }

    public static class AsyncEventsUsingTplExtension
    {
        public static void InvokeAsync<TEventArgs>
            (this EventHandler<TEventArgs> handler, object sender, TEventArgs args)
        {
            Task.Factory.StartNew(() =>
            {
                Console.WriteLine("InvokeAsync<tEventArgs> is running on ThreadId:{0}",
                    Thread.CurrentThread.ManagedThreadId);

                var delegates = handler?.GetInvocationList();

                foreach (var delegated in delegates)
                {
                    var myEventHandler = delegated as EventHandler<TEventArgs>;
                    if (myEventHandler != null)
                    {
                        Task.Factory.StartNew(() => myEventHandler(sender, args));
                    }
                }
            });
        }
    }

    internal class Client
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Client is running on threadId:{0}",
                Thread.CurrentThread.ManagedThreadId);

            ManualResetEvent[] mres = new ManualResetEvent[3];
            for (int i = 0; i < mres.Length; i++) mres[i] = new ManualResetEvent(false);

            EventWrapper s = new EventWrapper();
            s.EventW += (new HandlerWrapper("1", mres[0])).Handler;
            s.EventW += (new HandlerWrapper("2", mres[1])).Handler;
            s.EventW += (new HandlerWrapper("3", mres[2])).Handler;

            // Change suvbject state and notify observers
            s.StateW = "ABC123";

            var timer = new Stopwatch();
            timer.Start();

            s.Notify();

            ManualResetEvent.WaitAll(mres);
            timer.Stop();
            TimeSpan timeTaken = timer.Elapsed;
            string tmp1 = "client time taken: " + timeTaken.ToString(@"m\:ss\.fff");
            Console.WriteLine(tmp1);

            Console.ReadLine();
        }
    }
}

==> ./Observer_pattern6/Observer_pattern6/Program.cs <==
using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Diagnostics.Tracing;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;

namespace Observer_pattern6
{
    public class EventArgsW : EventArgs
    {
        public string StateW = null;
    }

    public class EventWrapper
    {
        public event AsyncEventHandler<EventArgsW> EventW;

        public string StateW;

        public async Task Notify(CancellationToken token)
        {
            Console.WriteLine("Notify is running on ThreadId:{0}",
                Thread.CurrentThread.ManagedThreadId);

            EventArgsW args = new EventArgsW();
            args.StateW = this.StateW;

            await this.EventW.InvokeAsync(this, args, token);
        }
    }

    public class HandlerWrapper
    {
        private string name;
        private string StateW;
        private ManualResetEvent mrs;

        public HandlerWrapper(string name, ManualResetEvent mrs)
        {
            this.name = name;
            this.mrs = mrs;
        }

        public async Task Handler(object subject, EventArgsW args,
            CancellationToken token)
        {
            Console.WriteLine("Handler{0} is running on ThreadId:{1}",
                name, Thread.CurrentThread.ManagedThreadId);

            await Worker(subject, args);
        }

        private async Task Worker(object subject, EventArgsW args)
        {
            Console.WriteLine("Handler{0}.Worker is running on ThreadId:{1}, i:0",
                name, Thread.CurrentThread.ManagedThreadId);
            StateW = args.StateW;

            for (int i = 1; i <= 2; ++i)
            {
                Thread.Sleep(5000);
                Console.WriteLine("Handler{0}.Worker is running on ThreadId:{1}, i:{2}",
                    name, Thread.CurrentThread.ManagedThreadId, i);
            }

            await Task.Delay(0);
            mrs.Set();
        }
    }

    public delegate Task AsyncEventHandler<TEventArgs>(
        object sender, TEventArgs e, CancellationToken token);

    public static class AsyncEventHandlerExtensions
    {
        public static async Task InvokeAsync<TEventArgs>(
            this AsyncEventHandler<TEventArgs> handler,
            object sender, TEventArgs args, CancellationToken token)
        {
            await Task.Run(async () =>
            {
                Console.WriteLine("InvokeAsync<TEventArgs> is running on ThreadId:{0}",
                    Thread.CurrentThread.ManagedThreadId);

                var delegates = handler?.GetInvocationList();
                if (delegates?.Length > 0)
                {
                    var tasks = delegates
                        .Cast<AsyncEventHandler<TEventArgs>>()
                        .Select(e => Task.Run(
                            async () => await e.Invoke(sender, args, token)
                            )
                        );
                    await Task.WhenAll(tasks);
                }
            }).ConfigureAwait(false);
        }
    }

    class Client
    {
        static async Task Main(string[] args)
        {
            Console.WriteLine("Client is running on ThreadId:{0}",
                Thread.CurrentThread.ManagedThreadId);

            ManualResetEvent[] mres = new ManualResetEvent[3];
            for (int i = 0; i < mres.Length; i++) mres[i] = new ManualResetEvent(false);

            EventWrapper s = new EventWrapper();
            s.EventW += (new HandlerWrapper("1", mres[0])).Handler;
            s.EventW += (new HandlerWrapper("2", mres[1])).Handler;
            s.EventW += (new HandlerWrapper("3", mres[2])).Handler;

            // Change subject state and notify observers
            s.StateW = "ABC123";

            var timer = new Stopwatch();
            timer.Start();

            await s.Notify(CancellationToken.None);

            ManualResetEvent.WaitAll(mres);
            timer.Stop();
            TimeSpan timeTaken = timer.Elapsed;
            string tmp1 = "Client time taken: " + timeTaken.ToString(@"m\:ss\.fff");
            Console.WriteLine(tmp1);

            Console.ReadLine();
        }
    }
}

==> source/repos/HelloWPF/HelloWPF/App.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace HelloWPF
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
    }
}

==> source/repos/HelloWPF/HelloWPF/AssemblyInfo.cs <==
using System.Windows;

[assembly: ThemeInfo(
    ResourceDictionaryLocation.None, //where theme specific resource dictionaries are located
                                     //(used if a resource is not found in the page,
                                     // or application resource dictionaries)
    ResourceDictionaryLocation.SourceAssembly //where the generic resource dictionary is located
                                              //(used if a resource is not found in the page,
                                              // app, or any theme specific resource dictionaries)
)]

==> source/repos/HelloWPF/HelloWPF/MainWindow.xaml.cs <==
﻿u
    sing System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace HelloWPF
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            textBoxNew.Text = "Hello WPF!";
        }
    }
}

==> source/repos/Observer_pattern1/Observer_pattern1/Program.cs <==
﻿using System;
using System.Collections.Generic;

namespace Observer_pattern1
{
    public class Args
    {
    }

    public abstract class ASubject
    {
        protected List<IObserver> observersList = new List<IObserver>();

        public void AddObserver(IObserver observer)
        {
            observersList.Add(observer);
        }

        public void RemoveObserver(IObserver observer)
        {
            observersList.Remove(observer);
        }
    }

    public interface IObserver
    {
        void Update(object subject, Args args);
    }

    public class Subject : ASubject
    {
        public string SubjectState = null;

        public void NotifyObservers()
        {
            ArgsSubject args = new ArgsSubject();
            args.SubjectState = this.SubjectState;

            foreach (IObserver o in observersList)
            {
                o.Update(this, args);
            }
        }
    }

    public class Observer : IObserver
    {
        private string name;
        private string observerState;

        public Observer(string name)
        {
            this.name = name;
        }

        public void Update(object s, Args args)
        {
            observerState = ((ArgsSubject)args).SubjectState;
            Console.WriteLine("Observer {0}'s new state is {1}",
                name, observerState);
        }
    }

    public class ArgsSubject : Args
    {
        public string SubjectState = null;
    }

    class Client
    {
        static void Main(string[] args)
        {
            Subject s = new Subject();
            s.AddObserver(new Observer("1"));
            s.AddObserver(new Observer("2"));
            s.AddObserver(new Observer("3"));

            // Change subject state and notify observers
            s.SubjectState = "ABC123";
            s.NotifyObservers();

            Console.ReadLine();
        }
    }
}

==> source/repos/Observer_pattern2/Obseerver_pattern2/Program.cs <==
﻿using System;
using System.IO.IsolatedStorage;

namespace Obseerver_pattern2
{
    public class Subject
    {
        public event EventHandler<EventArgsSubject> SubjectEvent;

        public string SubjectState;

        public void NotifyObservers()
        {
            EventArgsSubject args = new EventArgsSubject();
            args.SubjectState = this.SubjectState;

            // (1)
            if (SubjectEvent != null)
            {
                SubjectEvent(this, args);
            }
        }
    }

    public class Observer
    {
        private string name;
        private string observerState;

        public Observer(string name)
        {
            this.name = name;
        }

        public void Update(object subject, EventArgsSubject args)
        {
            observerState = args.SubjectState;
            Console.WriteLine("Observer {0}'s new state is {1}",
                name, observerState);
        }
    }

    public class EventArgsSubject : EventArgs
    {
        public string SubjectState = null;
    }

    class Client
    {
        static void Main(string[] args)
        {
            Subject s = new Subject();
            s.SubjectEvent += (new Observer("1")).Update;
            s.SubjectEvent += (new Observer("2")).Update;
            s.SubjectEvent += (new Observer("3")).Update;

            s.SubjectState = "ABC123";
            s.NotifyObservers();

            Console.ReadLine();
        }
    }
}

==> source/repos/Observer_pattern3/Observer_pattern3/Program.cs <==
﻿using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Threading;

namespace Observer_pattern3
{
    public class EventArgsW : EventArgs
    {
        public string StateW = null;
    }

    public class EventWrapper
    {
        public event EventHandler<EventArgsW> EventW;

        public string StateW;

        public void Notify()
        {
            Console.WriteLine("Notify is running on ThreadId:{0}",
                Thread.CurrentThread.ManagedThreadId);

            EventArgsW args = new EventArgsW();
            args.StateW = this.StateW;

            EventW?.Invoke(this, args);
        }
    }

    public class HandlerWrapper
    {
        private string name;
        private string StateW;
        private ManualResetEvent mrs;

        public HandlerWrapper(string name, ManualResetEvent mrs)
        {
            this.name = name;
            this.mrs = mrs;
        }

        public void Handler(object subject, EventArgsW args)
        {
            Console.WriteLine("Handler{0} is running on ThreadId:{1}",
                name, Thread.CurrentThread.ManagedThreadId);

            Worker(subject, args);
        }

        private void Worker(object subject, EventArgsW args)
        {
            Console.WriteLine("Handler{0}.Worker is running on Threadid:{1}, i:0",
                name, Thread.CurrentThread.ManagedThreadId);
            StateW = args.StateW;

            for (int i = 1; i <= 2; ++i)
            {
                Thread.Sleep(5000);
                Console.WriteLine("Handler{0}.Worker is running on Threadid:{1}, i:0",
                    name, Thread.CurrentThread.ManagedThreadId);
            }

            mrs.Set();
        }
    }

    class Client
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Client is running on ThreadId:{0}",
                Thread.CurrentThread.ManagedThreadId);

            ManualResetEvent[] mres = new ManualResetEvent[3];
            for (int i = 0; i < mres.Length; i++) mres[i] = new ManualResetEvent(false);

            EventWrapper s = new EventWrapper();
            s.EventW += (new HandlerWrapper("1", mres[0])).Handler;
            s.EventW += (new HandlerWrapper("2", mres[1])).Handler;
            s.EventW += (new HandlerWrapper("3", mres[2])).Handler;

            // Change subject state and notify observers
            s.StateW = "ABC123";

            var timer = new Stopwatch();
            timer.Start();

            s.Notify();

            ManualResetEvent.WaitAll(mres);
            timer.Stop();
            TimeSpan timeTaken = timer.Elapsed;
            string tmp1 = "Client time taken: " + timeTaken.ToString(@"m\:ss\.fff");
            Console.WriteLine(tmp1);

            Console.ReadLine();
        }
    }
}

==> source/repos/Observer_pattern4/Observer_pattern4/Program.cs <==
﻿using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;

namespace Observer_pattern4
{
    public class EventArgsW : EventArgs
    {
        public string StateW = null;
    }

    public class EventWrapper
    {
        public event EventHandler<EventArgsW> EventW;

        public string StateW;

        public void Notify()
        {
            Task.Factory.StartNew(
                () => {
                    Console.WriteLine("Notify is running on ThreadId:{0}",
                        Thread.CurrentThread.ManagedThreadId);

                    EventArgsW args = new EventArgsW();
                    args.StateW = this.StateW;

                    EventW?.Invoke(this, args);
                });
        }
    }

    public class HandlerWrapper
    {
        private string name;
        private string StateW;
        private ManualResetEvent mrs;

        public HandlerWrapper(string name, ManualResetEvent mrs)
        {
            this.name = name;
            this.mrs = mrs;
        }

        public void Handler(object subject, EventArgsW args)
        {
            Console.WriteLine("Handler{0} is running on Threadid:{1}",
                name, Thread.CurrentThread.ManagedThreadId);

            Task.Factory.StartNew(
                () => Worker(subject, args));
        }

        private void Worker(object subject, EventArgsW args)
        {
            Console.WriteLine("Handler{0}.Worker is running on threadId:{1}, i:0",
                name, Thread.CurrentThread.ManagedThreadId);
            StateW = args.StateW;

            for (int i = 1; i <= 2; ++i)
            {
                Thread.Sleep(5000);
                Console.WriteLine("Handler{0}.Worker is running on ThreadId:{1}, i:{2}",
                    name, Thread.CurrentThread.ManagedThreadId, i);
            }
            mrs.Set();
        }
    }

    internal class Client
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Client is running on threadId:{0}",
                Thread.CurrentThread.ManagedThreadId);

            ManualResetEvent[] mres = new ManualResetEvent[3];
            for (int i = 0; i < mres.Length; i++) mres[i] = new ManualResetEvent(false);

            EventWrapper s = new EventWrapper();
            s.EventW += (new HandlerWrapper("1", mres[0])).Handler;
            s.EventW += (new HandlerWrapper("2", mres[1])).Handler;
            s.EventW += (new HandlerWrapper("3", mres[2])).Handler;

            // change subject state and notify observers
            s.StateW = "ABC123";

            var timer = new Stopwatch();
            timer.Start();

            s.Notify();

            ManualResetEvent.WaitAll(mres);
            timer.Stop();
            TimeSpan timeTaken = timer.Elapsed;
            string tmp1 = "Client time taken: " + timeTaken.ToString(@"m\:ss\.fff");
            Console.WriteLine(tmp1);

            Console.ReadLine();
        }
    }
}

==> source/repos/Observer_pattern5/Observer_pattern5/Program.cs <==
﻿using System;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;

namespace Observer_pattern5
{
    public class EventArgsW : EventArgs
    {
        public string StateW = null;
    }

    public class EventWrapper
    {
        public event EventHandler<EventArgsW> EventW;

        public string StateW;

        public void Notify()
        {
            Console.WriteLine("Notify is running on ThreadId:{0}",
                Thread.CurrentThread.ManagedThreadId);

            EventArgsW args = new EventArgsW();
            args.StateW = this.StateW;

            EventW?.InvokeAsync<EventArgsW>(this, args);
        }
    }

    public class HandlerWrapper
    {
        private string name;
        private string StateW;
        private ManualResetEvent mrs;

        public HandlerWrapper(string name, ManualResetEvent mrs)
        {
            this.name = name;
            this.mrs = mrs;
        }

        public void Handler(object subject, EventArgsW args)
        {
            Console.WriteLine("Handler{0} is running on Threadid:{1}",
                name, Thread.CurrentThread.ManagedThreadId);

            Worker(subject, args);
        }

        private void Worker(object subject, EventArgsW args)
        {
            Console.WriteLine("Handler{0}.Worker is running on ThreadId:{1}, i:0",
                name, Thread.CurrentThread.ManagedThreadId);
            StateW = args.StateW;

            for (int i = 1; i <= 2; ++i)
            {
                Thread.Sleep(5000);
                Console.WriteLine("Handler{0}.Worker is running on ThreadId:{1}, i:{2}",
                    name, Thread.CurrentThread.ManagedThreadId, i);
            }
        }
    }

    public static class AsyncEventsUsingTplExtension
    {
        public static void InvokeAsync<TEventArgs>
            (this EventHandler<TEventArgs> handler, object sender, TEventArgs args)
        {
            Task.Factory.StartNew(() =>
            {
                Console.WriteLine("InvokeAsync<tEventArgs> is running on ThreadId:{0}",
                    Thread.CurrentThread.ManagedThreadId);

                var delegates = handler?.GetInvocationList();

                foreach (var delegated in delegates)
                {
                    var myEventHandler = delegated as EventHandler<TEventArgs>;
                    if (myEventHandler != null)
                    {
                        Task.Factory.StartNew(() => myEventHandler(sender, args));
                    }
                }
            });
        }
    }

    internal class Client
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Client is running on threadId:{0}",
                Thread.CurrentThread.ManagedThreadId);

            ManualResetEvent[] mres = new ManualResetEvent[3];
            for (int i = 0; i < mres.Length; i++) mres[i] = new ManualResetEvent(false);

            EventWrapper s = new EventWrapper();
            s.EventW += (new HandlerWrapper("1", mres[0])).Handler;
            s.EventW += (new HandlerWrapper("2", mres[1])).Handler;
            s.EventW += (new HandlerWrapper("3", mres[2])).Handler;

            // Change suvbject state and notify observers
            s.StateW = "ABC123";

            var timer = new Stopwatch();
            timer.Start();

            s.Notify();

            ManualResetEvent.WaitAll(mres);
            timer.Stop();
            TimeSpan timeTaken = timer.Elapsed;
            string tmp1 = "client time taken: " + timeTaken.ToString(@"m\:ss\.fff");
            Console.WriteLine(tmp1);

            Console.ReadLine();
        }
    }
}

==> source/repos/Observer_pattern6/Observer_pattern6/Program.cs <==
﻿using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Diagnostics.Tracing;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;

namespace Observer_pattern6
{
    public class EventArgsW : EventArgs
    {
        public string StateW = null;
    }

    public class EventWrapper
    {
        public event AsyncEventHandler<EventArgsW> EventW;

        public string StateW;

        public async Task Notify(CancellationToken token)
        {
            Console.WriteLine("Notify is running on ThreadId:{0}",
                Thread.CurrentThread.ManagedThreadId);

            EventArgsW args = new EventArgsW();
            args.StateW = this.StateW;

            await this.EventW.InvokeAsync(this, args, token);
        }
    }

    public class HandlerWrapper
    {
        private string name;
        private string StateW;
        private ManualResetEvent mrs;

        public HandlerWrapper(string name, ManualResetEvent mrs)
        {
            this.name = name;
            this.mrs = mrs;
        }

        public async Task Handler(object subject, EventArgsW args,
            CancellationToken token)
        {
            Console.WriteLine("Handler{0} is running on ThreadId:{1}",
                name, Thread.CurrentThread.ManagedThreadId);

            await Worker(subject, args);
        }

        private async Task Worker(object subject, EventArgsW args)
        {
            Console.WriteLine("Handler{0}.Worker is running on ThreadId:{1}, i:0",
                name, Thread.CurrentThread.ManagedThreadId);
            StateW = args.StateW;

            for (int i = 1; i <= 2; ++i)
            {
                Thread.Sleep(5000);
                Console.WriteLine("Handler{0}.Worker is running on ThreadId:{1}, i:{2}",
                    name, Thread.CurrentThread.ManagedThreadId, i);
            }

            await Task.Delay(0);
            mrs.Set();
        }
    }

    public delegate Task AsyncEventHandler<TEventArgs>(
        object sender, TEventArgs e, CancellationToken token);

    public static class AsyncEventHandlerExtensions
    {
        public static async Task InvokeAsync<TEventArgs>(
            this AsyncEventHandler<TEventArgs> handler,
            object sender, TEventArgs args, CancellationToken token)
        {
            await Task.Run(async () =>
            {
                Console.WriteLine("InvokeAsync<TEventArgs> is running on ThreadId:{0}",
                    Thread.CurrentThread.ManagedThreadId);

                var delegates = handler?.GetInvocationList();
                if (delegates?.Length > 0)
                {
                    var tasks = delegates
                        .Cast<AsyncEventHandler<TEventArgs>>()
                        .Select(e => Task.Run(
                            async () => await e.Invoke(sender, args, token)
                            )
                        );
                    await Task.WhenAll(tasks);
                }
            }).ConfigureAwait(false);
        }
    }

    class Client
    {
        static async Task Main(string[] args)
        {
            Console.WriteLine("Client is running on ThreadId:{0}",
                Thread.CurrentThread.ManagedThreadId);

            ManualResetEvent[] mres = new ManualResetEvent[3];
            for (int i = 0; i < mres.Length; i++) mres[i] = new ManualResetEvent(false);

            EventWrapper s = new EventWrapper();
            s.EventW += (new HandlerWrapper("1", mres[0])).Handler;
            s.EventW += (new HandlerWrapper("2", mres[1])).Handler;
            s.EventW += (new HandlerWrapper("3", mres[2])).Handler;

            // Change subject state and notify observers
            s.StateW = "ABC123";

            var timer = new Stopwatch();
            timer.Start();

            await s.Notify(CancellationToken.None);

            ManualResetEvent.WaitAll(mres);
            timer.Stop();
            TimeSpan timeTaken = timer.Elapsed;
            string tmp1 = "Client time taken: " + timeTaken.ToString(@"m\:ss\.fff");
            Console.WriteLine(tmp1);

            Console.ReadLine();
        }
    }
}

==> source/repos/WpfAppBinding/WpfAppBinding/App.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace WpfAppBinding
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
    }
}

==> source/repos/WpfAppBinding/WpfAppBinding/AssemblyInfo.cs <==
using System.Windows;

[assembly: ThemeInfo(
    ResourceDictionaryLocation.None, //where theme specific resource dictionaries are located
                                     //(used if a resource is not found in the page,
                                     // or application resource dictionaries)
    ResourceDictionaryLocation.SourceAssembly //where the generic resource dictionary is located
                                              //(used if a resource is not found in the page,
                                              // app, or any theme specific resource dictionaries)
)]

==> source/repos/WpfAppBinding/WpfAppBinding/MainWindow.xaml.cs <==
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Globalization;
using System.Text.RegularExpressions;
using System.Collections.ObjectModel;
using System.Windows.Markup;
using System.IO;
using System.ComponentModel;

/// <summary>
/// To debug errors too do with binding in the XAML code, run an application in Debug mode, 
/// Manually go throughthe screens, and look at the debug output window in Visual Studio for 
/// lines that start with "System.Data.Error", will report information about binding errors
/// </summary>
namespace WpfAppBinding
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public Classroom _Students = new Classroom();

        public MainWindow()
        {
            InitializeComponent();

            // Set the logical focus to the window
            Focus();
        }

        /// <summary>
        /// How to get a Bitmap from a visual
        /// </summary>
        /// <param name="visual"></param>
        /// <param name="width"></param>
        /// <param name="height"></param>
        /// <param name="filePath"></param>
        public void SaveImage(Visual visual, int width, int height, string filePath)
        {
            RenderTargetBitmap bitmap = new RenderTargetBitmap(width, height, 96, 96,
                                                         PixelFormats.Pbgra32);
            bitmap.Render(visual);

            PngBitmapEncoder image = new PngBitmapEncoder();
            image.Frames.Add(BitmapFrame.Create(bitmap));
            using (Stream fs = File.Create(filePath))
            {
                image.Save(fs);
            }
        }

        private void ListBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }
    }

    public class Notifier : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        protected void OnPropertyChanged(string propertyName)
        {
            if(PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }
    }

    public class BoolToStringConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value is Boolean)
            {
                return ((bool)value) ? "Checked" : "Not checked";
            }

            return value;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }

    /// <summary>
    /// Validates a text against a regular expression
    /// </summary>
    public class RegexValidationRule : ValidationRule
    {
        private string _pattern;
        private Regex _regex;

        public string Pattern
        {
            get { return _pattern; }
            set
            {
                _pattern = value;
                _regex = new Regex(_pattern, RegexOptions.IgnoreCase);
            }
        }
        public RegexValidationRule()
        {
        }

        public override ValidationResult Validate(object value, CultureInfo cultureinfo)
        {
            if (value == null || !_regex.Match(value.ToString()).Success)
            {
                return new ValidationResult(false, "The value is not a valid email address");
            }
            else 
            {
                return new ValidationResult(true, null);
            }
        }
    }

    //The converter is both, a value converter and a markup extension. This allows you to create and use it at the same time.
    [ValueConversion(typeof(ReadOnlyObservableCollection<ValidationError>), typeof(string))]
    public class ValidationErrorsToStringConverter : MarkupExtension, IValueConverter
    {
        public override object ProvideValue(IServiceProvider serviceProvider)
        {
            return new ValidationErrorsToStringConverter();
        }

        public object Convert(object value, Type targettype, object parameter, CultureInfo cultureInfo)
        {
            ReadOnlyObservableCollection<ValidationError> errors = value as ReadOnlyObservableCollection<ValidationError>;

            if (errors == null)
            {
                return string.Empty;
            }

            return string.Join("\n", (from e in errors select e.ErrorContent as string).ToArray());
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }

    public class Pupil : Notifier
    {
        private int _height;
        public int _weight;

        public Pupil()
        {
            _height = 0;
        }

        public int _Height
        {
            get { return _height; }
            set
            {
                _height = value;
                OnPropertyChanged("_height");
            }
        }
    }

    public class Classroom : Notifier
    {
        private List<Pupil> _pupilList = new List<Pupil>();
        public ObservableCollection<string> _names = new ObservableCollection<string>() { "Jon", "Jane", "May" };

        public List<Pupil> _PupilList
        {
            get { return _pupilList; }
            set
            {
                if (_pupilList == null && value == null)
                {
                    _pupilList = new List<Pupil>();
                    OnPropertyChanged("_pupilList");
                }
                else
                {
                    _pupilList = value;
                    OnPropertyChanged("_pupilList");
                }
            }
        }

        public Classroom()
        {
            for (int i = 0; i < 10; i++)
            {
                _PupilList.Add(new Pupil()
                {
                    _weight = (i * 2) + 40
                }); 
            }
        }
    }
}
==> learnwpfexercises/BikeShop/BikeShop/App.xaml <==
﻿<Application x:Class="BikeShop.App"
             xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
             xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
             xmlns:local="clr-namespace:BikeShop"
             StartupUri="MainWindow.xaml">
    <Application.Resources>
        <LinearGradientBrush x:Key="background">
            <GradientStop Color="#FFDBFFE7"
                          Offset="0" />
            <GradientStop Color="#FF03882D"
                          Offset="1" />
        </LinearGradientBrush>
    </Application.Resources>
</Application>

==> learnwpfexercises/BikeShop/BikeShop/Contact.xaml <==
﻿<Page x:Class="BikeShop.Contact"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008" 
      xmlns:local="clr-namespace:BikeShop"
      mc:Ignorable="d" 
      d:DesignHeight="300" d:DesignWidth="300"
      Title="Contact"
      Background="{StaticResource background}">

    <Grid>
        <TextBlock x:Name="textBlock"
                   HorizontalAlignment="Left"
                   Margin="10,11,0,0"
                   TextWrapping="Wrap"
                   Text="Sender"
                   VerticalAlignment="Top" />
        <TextBlock x:Name="textBlock1"
                   HorizontalAlignment="Left"
                   Margin="10,39,0,0"
                   TextWrapping="Wrap"
                   Text="Message"
                   VerticalAlignment="Top" />
        <TextBox x:Name="textBox"
                 HorizontalAlignment="Left"
                 Height="23"
                 Margin="71,10,0,0"
                 TextWrapping="Wrap"
                 VerticalAlignment="Top"
                 Width="439" />
        <TextBox x:Name="textBox1"
                 HorizontalAlignment="Left"
                 Height="275"
                 Margin="71,38,0,0"
                 TextWrapping="Wrap"
                 VerticalAlignment="Top"
                 Width="439" />
    </Grid>
</Page>

==> learnwpfexercises/BikeShop/BikeShop/Discussion.xaml <==
﻿<Page x:Class="BikeShop.Discussion"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
      xmlns:local="clr-namespace:BikeShop"
      xmlns:data="clr-namespace:BikeShop"
      mc:Ignorable="d"
      d:DesignHeight="300"
      d:DesignWidth="300"
      Title="Discussion"
      Background="{StaticResource background}">

    <Grid>
        <Grid.ColumnDefinitions>
            <ColumnDefinition Width="*" />
            <ColumnDefinition Width="100" />
        </Grid.ColumnDefinitions>
        <Grid.RowDefinitions>
            <RowDefinition Height="*" />
            <RowDefinition Height="50" />
        </Grid.RowDefinitions>
        <ListBox Grid.ColumnSpan="2"
                 Margin="5">
            <ListBox.ItemsSource>
                <data:Talk />
            </ListBox.ItemsSource>
            <ListBox.ItemTemplate>
                <DataTemplate>
                    <StackPanel Width="300">
                        <StackPanel Orientation="Horizontal">
                            <Image Source="chat.png" Width="20" />
                            <TextBlock Text="{Binding Sender}" />
                        </StackPanel>
                        <TextBlock Text="{Binding Content}"
                                   Margin="20,0,0,0"
                                   TextWrapping="Wrap" />
                    </StackPanel>
                </DataTemplate>
            </ListBox.ItemTemplate>
        </ListBox>
        <Button Grid.Row="1"
                Grid.Column="1"
                Margin="5"
                Background="Orange"
                Content="Send">
            <Button.Template>
                <ControlTemplate TargetType="Button">
                    <Grid>
                        <Ellipse Fill="#AA000000" Margin="10, 10, 0, 0" />
                        <Ellipse Fill="{TemplateBinding Background}" Margin="0, 0, 10, 10" />
                        <Viewbox Margin="5, 5, 15, 15">
                            <ContentPresenter />
                        </Viewbox>
                    </Grid>
                </ControlTemplate>
            </Button.Template>
        </Button>
        <TextBox Grid.Row="1"
                 Margin="5"
                 Text="Type your message here" />
    </Grid>
</Page>

==> learnwpfexercises/BikeShop/BikeShop/MainWindow.xaml <==
﻿<Window x:Class="BikeShop.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:BikeShop"
        mc:Ignorable="d"
        Title="MainWindow"
        Height="350"
        Width="525">
    <Grid>
        <Frame Source="/Menu.xaml" />
    </Grid>
</Window>

==> learnwpfexercises/BikeShop/BikeShop/Menu.xaml <==
﻿<Page x:Class="BikeShop.Menu"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
      xmlns:local="clr-namespace:BikeShop"
      mc:Ignorable="d"
      d:DesignHeight="300"
      d:DesignWidth="300"
      Title="Menu"
      Background="{StaticResource background}">
    <Page.Resources>
        <Style TargetType="Button">
            <Setter Property="Template">
                <Setter.Value>
                    <ControlTemplate TargetType="Button">
                        <Grid>
                            <Ellipse Fill="#AA000000"
                                     Margin="10, 10, 0, 0" />
                            <Ellipse Fill="{TemplateBinding Background}"
                                     Margin="0, 0, 10, 10" />
                            <Viewbox Margin="5, 5, 15, 15">
                                <ContentPresenter />
                            </Viewbox>
                        </Grid>
                    </ControlTemplate>
                </Setter.Value>
            </Setter>
        </Style>
    </Page.Resources>
    <Grid HorizontalAlignment="Center"
          VerticalAlignment="Center">
        <Button x:Name="button"
                Content="Products"
                HorizontalAlignment="Left"
                Margin="10,9,0,0"
                VerticalAlignment="Top"
                Width="80"
                Height="80"
                Click="button_Click"
                Background="#FF7161E1"
                Foreground="White" />
        <Button x:Name="button1"
                Content="Live support"
                HorizontalAlignment="Left"
                Margin="109,9,0,0"
                VerticalAlignment="Top"
                Width="80"
                Height="80"
                Click="button1_Click"
                Background="#FFDD6F31"
                Foreground="White" />
        <Button x:Name="button2"
                Content="Email support"
                HorizontalAlignment="Left"
                Margin="206,9,0,0"
                VerticalAlignment="Top"
                Width="80"
                Height="80"
                Click="button2_Click"
                Background="#FF9F0043"
                Foreground="White" />
        <TextBlock x:Name="textBlock"
                   HorizontalAlignment="Left"
                   Margin="53,118,0,0"
                   TextWrapping="Wrap"
                   Text="Adventure Works"
                   VerticalAlignment="Top"
                   FontWeight="Bold"
                   FontStyle="Italic"
                   FontSize="24" />

    </Grid>
</Page>

==> learnwpfexercises/BikeShop/BikeShop/ProductsManagement.xaml <==
﻿<Page x:Class="BikeShop.ProductsManagement"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
      xmlns:local="clr-namespace:BikeShop"
      mc:Ignorable="d"
      d:DesignHeight="328.286"
      d:DesignWidth="454.286"
      Background="{StaticResource background}"
      Title="ProductsManagement">

    <Grid>
        <TextBox x:Name="textBox"
                 Height="23"
                 Margin="59,10,113.222,0"
                 TextWrapping="Wrap"
                 VerticalAlignment="Top"
                 Background="#99FFFFFF"
                 TextChanged="textBox_TextChanged" />
        <TextBlock x:Name="textBlock"
                   HorizontalAlignment="Left"
                   Margin="10,11,0,0"
                   TextWrapping="Wrap"
                   Text="Search:"
                   VerticalAlignment="Top" />
        <DataGrid x:Name="dataGrid"
                  Margin="10,60,191.222,10.444" />
        <Border Margin="0,60,10.222,10.444"
                DataContext="{Binding SelectedItem, ElementName=dataGrid}"
                HorizontalAlignment="Right"
                Width="162"
                Background="#66FFFFFF">
            <StackPanel Margin="10">
                <TextBlock Text="Product details"
                           FontWeight="Bold"
                           FontSize="16"
                           HorizontalAlignment="Center"
                           Margin="10" />
                <TextBlock Text="Title" />
                <TextBox Text="{Binding Title, Mode=TwoWay}" />
                <TextBlock Text="Price" />
                <TextBox Text="{Binding Price, Mode=TwoWay}" />
                <TextBlock Text="Color" />
                <TextBox Text="{Binding Color, Mode=TwoWay}" />
                <Border Background="{Binding Color}"
                        Height="10" />
                <TextBlock Text="Reference" />
                <TextBox Text="{Binding Reference, Mode=TwoWay}" />
            </StackPanel>
        </Border>

    </Grid>
</Page>

==> learnwpfexercises/BikeShop/BikeShop/ProductsManagementMVVM.xaml <==
﻿<Page x:Class="BikeShop.ProductsManagementMVVM"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008" 
      xmlns:local="clr-namespace:BikeShop"
      xmlns:vm="clr-namespace:BikeShop"
      mc:Ignorable="d" 
      d:DesignHeight="300" d:DesignWidth="300"
      Background="{StaticResource background}"
      Title="ProductsManagementMVVM">
    <Page.DataContext>
        <vm:ProductsManagementMVVMViewModel />
    </Page.DataContext>

    <Grid>
        <TextBox Text="{Binding SearchInput, Mode=TwoWay, UpdateSourceTrigger=PropertyChanged}"
                 Height="23"
                 Margin="59,10,113.222,0"
                 TextWrapping="Wrap"
                 VerticalAlignment="Top"
                 Background="#99FFFFFF" />
        <TextBlock x:Name="textBlock"
                   HorizontalAlignment="Left"
                   Margin="10,11,0,0"
                   TextWrapping="Wrap"
                   Text="Search:"
                   VerticalAlignment="Top" />
        <DataGrid ItemsSource="{Binding FoundProducts}"
                  SelectedItem="{Binding SelectedProduct, Mode=TwoWay}"
                  Margin="10,60,191.222,10.444" />
        <Border DataContext="{Binding SelectedProduct}"
                Margin="0,60,10.222,10.444"
                HorizontalAlignment="Right"
                Width="162"
                Background="#66FFFFFF">
            <StackPanel Margin="10">
                <TextBlock Text="Product details"
                        FontWeight="Bold"
                        FontSize="16"
                        HorizontalAlignment="Center"
                        Margin="10" />
                <TextBlock Text="Title" />
                <TextBox Text="{Binding Title, Mode=TwoWay}" />
                <TextBlock Text="Price" />
                <TextBox Text="{Binding Price, Mode=TwoWay}" />
                <TextBlock Text="Color" />
                <TextBox Text="{Binding Color, Mode=TwoWay}" />
                <Border Background="{Binding Color}"
                        Height="10" />
                <TextBlock Text="Reference" />
                <TextBox Text="{Binding Reference, Mode=TwoWay}" />
            </StackPanel>
        </Border>


    </Grid>
</Page>

==> learnwpfexercises/WpfDemos/WpfDemos/App.xaml <==
﻿<Application x:Class="WpfDemos.App"
             xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
             xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
             xmlns:local="clr-namespace:WpfDemos"
             StartupUri="CurrencyConverter2.xaml">
    <Application.Resources>
         
    </Application.Resources>
</Application>

==> learnwpfexercises/WpfDemos/WpfDemos/CollectionOfCars.xaml <==
﻿<Page x:Class="WpfDemos.CollectionOfCars"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008" 
      xmlns:local="clr-namespace:WpfDemos"

      mc:Ignorable="d" 
      d:DesignHeight="300" d:DesignWidth="300"
      Title="CollectionOfCars">
    <Page.Resources>
        <Style TargetType="ListBox">
            <Setter Property="Margin"
                    Value="10" />
        </Style>
    </Page.Resources>
    <WrapPanel>
        <ListBox ItemsSource="{Binding}" Margin="10">
            <ListBox.ItemTemplate>
                <DataTemplate>
                    <TextBlock Text="{Binding Speed}" />
                </DataTemplate>
            </ListBox.ItemTemplate>
        </ListBox>
        <ListBox ItemsSource="{Binding}">
            <ListBox.ItemTemplate>
                <DataTemplate>
                    <StackPanel>
                        <TextBlock Text="Speed" />
                        <TextBox Text="{Binding Speed}" />
                        <Slider Value="{Binding Speed}" Maximum="100" />
                        <TextBlock Text="Color" />
                        <Border Height="10">
                            <Border.Background>
                                <SolidColorBrush Color="{Binding Color}" />
                            </Border.Background>
                        </Border>
                        <TextBox Text="{Binding Color}" />
                    </StackPanel>
                </DataTemplate>
            </ListBox.ItemTemplate>
        </ListBox>
    </WrapPanel>
</Page>

==> learnwpfexercises/WpfDemos/WpfDemos/CurrencyConverter.xaml <==
﻿<Page x:Class="WpfDemos.CurrencyConverter"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:WpfDemos"
        mc:Ignorable="d"
        xmlns:vm="clr-namespace:WpfDemos"
        Title="CurrencyConverter"
        Height="93"
        Width="234.857">
    <Page.DataContext>
        <vm:CurrencyConverterViewModel />
    </Page.DataContext>
    <Grid>
        <TextBox x:Name="textBox"
                 HorizontalAlignment="Left"
                 Height="23"
                 Margin="98,10,0,0"
                 TextWrapping="Wrap"
                 Text="{Binding Euros, UpdateSourceTrigger=PropertyChanged}"
                 VerticalAlignment="Top"
                 Width="120" />
        <TextBlock x:Name="textBlock"
                   HorizontalAlignment="Left"
                   Margin="98,38,0,0"
                   TextWrapping="Wrap"
                   Text="{Binding Dollars}"
                   VerticalAlignment="Top" />
        <TextBlock x:Name="textBlock1"
                   HorizontalAlignment="Left"
                   Margin="10,11,0,0"
                   TextWrapping="Wrap"
                   Text="Amount in €"
                   VerticalAlignment="Top" />
        <TextBlock x:Name="textBlock1_Copy"
                   HorizontalAlignment="Left"
                   Margin="10,38,0,0"
                   TextWrapping="Wrap"
                   Text="Amount in US $"
                   VerticalAlignment="Top" />

    </Grid>
</Page>

==> learnwpfexercises/WpfDemos/WpfDemos/CurrencyConverter2.xaml <==
﻿<Page x:Class="WpfDemos.CurrencyConverter2"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
      xmlns:local="clr-namespace:WpfDemos"
      xmlns:vm="clr-namespace:WpfDemos"
      mc:Ignorable="d"
      d:DesignHeight="96.429"
      d:DesignWidth="275.143"
      Title="CurrencyConverter2">
    <Page.DataContext>
        <vm:CurrencyConverterViewModel2 />
    </Page.DataContext>
    <Grid>
        <TextBox x:Name="textBox"
                 HorizontalAlignment="Left"
                 Height="23"
                 Margin="141,39,0,0"
                 TextWrapping="Wrap"
                 Text="{Binding Euros, UpdateSourceTrigger=PropertyChanged}"
                 VerticalAlignment="Top"
                 Width="120" />
        <TextBlock x:Name="textBlock"
                   HorizontalAlignment="Left"
                   Margin="141,66,0,0"
                   TextWrapping="Wrap"
                   Text="{Binding Converted}"
                   VerticalAlignment="Top" />
        <TextBlock x:Name="textBlock1"
                   HorizontalAlignment="Left"
                   Margin="10,40,0,0"
                   TextWrapping="Wrap"
                   Text="Amount in €"
                   VerticalAlignment="Top" />
        <TextBlock x:Name="textBlock1_Copy"
                   HorizontalAlignment="Left"
                   Margin="10,67,0,0"
                   TextWrapping="Wrap"
                   Text="{Binding ResultText}"
        VerticalAlignment="Top" />
        <TextBlock x:Name="textBlock2"
                   HorizontalAlignment="Left"
                   Margin="10,10,0,0"
                   TextWrapping="Wrap"
                   Text="Currency"
                   VerticalAlignment="Top" />
        <ComboBox x:Name="comboBox"
                  SelectedItem="{Binding SelectedCurrency}"
                  ItemsSource="{Binding Currencies}"
                  HorizontalAlignment="Left"
                  Margin="141,10,0,0"
                  VerticalAlignment="Top"
                  Width="120">
            <ComboBox.ItemTemplate>
                <DataTemplate>
                    <TextBlock Text="{Binding Title}" />
                </DataTemplate>
            </ComboBox.ItemTemplate>
        </ComboBox>

    </Grid>
</Page>

==> learnwpfexercises/WpfDemos/WpfDemos/LayoutVsRender.xaml <==
﻿<Page x:Class="WpfDemos.LayoutVsRender"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
      xmlns:local="clr-namespace:WpfDemos"
      mc:Ignorable="d"
      d:DesignHeight="284.571"
      d:DesignWidth="466.714"
      Title="LayoutVsRender">
    <Page.Resources>
        <Style TargetType="ListBox">
            <Setter Property="Margin"
                    Value="10" />
            <Setter Property="VerticalAlignment"
                    Value="Center" />
        </Style>
    </Page.Resources>

    <StackPanel Orientation="Horizontal"
                HorizontalAlignment="Center"
                VerticalAlignment="Center">
        <ListBox>
            <TextBlock Text="First element" />
            <TextBlock Text="Second element" />
            <GroupBox Header="Third element">
                Using some content is funnier
                <GroupBox.RenderTransform>
                    <RotateTransform Angle="-20" />
                </GroupBox.RenderTransform>
            </GroupBox>
        </ListBox>
        <ListBox>
            <TextBlock Text="First element" />
            <TextBlock Text="Second element" />
            <GroupBox Header="Third element">
                Using some content is funnier
                <GroupBox.LayoutTransform>
                    <RotateTransform Angle="-20" />
                </GroupBox.LayoutTransform>
            </GroupBox>
        </ListBox>
    </StackPanel>
</Page>

==> learnwpfexercises/WpfDemos/WpfDemos/MainWindow.xaml <==
﻿<Window x:Class="WpfDemos.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:WpfDemos"
        mc:Ignorable="d"
        Title="MainWindow" Height="350" Width="525">
    <Grid>
        <Frame Source="/LayoutVsRender.xaml" />
    </Grid>
</Window>

==> learnwpfexercises/WpfDemos/WpfDemos/SelectionControls.xaml <==
﻿<Page x:Class="WpfDemos.SelectionControls"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008" 
      xmlns:local="clr-namespace:WpfDemos"
      mc:Ignorable="d" 
      d:DesignHeight="300" d:DesignWidth="300"
      Title="SelectionControls">

    <Grid>
        <WrapPanel Margin="10">
            <ComboBox Margin="100">
                <Label>Element 1</Label>
                <Label>Element 2</Label>
                <GroupBox Header="Element 3">
                    With some content it's funnier
                </GroupBox>
            </ComboBox>

        </WrapPanel>
    </Grid>
</Page>

==> learnwpfexercises/WpfDemos/WpfDemos/Sizing.xaml <==
﻿<Window x:Class="WpfDemos.Sizing"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:WpfDemos"
        mc:Ignorable="d"
        Title="Sizing" Height="300" Width="300">
    <Border BorderBrush="Gray" BorderThickness="1"
            Padding="4"
            HorizontalAlignment="Center"
            VerticalAlignment="Center">

        <Grid Width="200" Height="100">
            <Grid.ColumnDefinitions>
                <ColumnDefinition />
                <ColumnDefinition />
            </Grid.ColumnDefinitions>
            <Grid.RowDefinitions>
                <RowDefinition />
                <RowDefinition />
            </Grid.RowDefinitions>
            <Button Grid.Row="0"
                    Grid.Column="0">Button A</Button>
            <Button Grid.Row="1"
                    Grid.Column="0">Button B</Button>
            <Button Grid.Row="1"
                    Grid.Column="1">Button C</Button>
            <Button Grid.Row="0"
                    Grid.Column="1">Button D</Button>
        </Grid>


    </Border>
</Window>

==> learnwpfexercises/WpfDemos/WpfDemos/Styling.xaml <==
﻿<Page x:Class="WpfDemos.Styling"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008" 
      xmlns:local="clr-namespace:WpfDemos"
      mc:Ignorable="d" 
      d:DesignHeight="300" d:DesignWidth="300"
      Title="Styling">
    <Page.Resources>
        <Style TargetType="Button">
            <Setter Property="Width"
                    Value="50" />
            <Setter Property="Height"
                    Value="50" />
            <Setter Property="Background">
                <Setter.Value>
                    <LinearGradientBrush>
                        <GradientStop Color="Red" />
                        <GradientStop Color="Yellow" Offset="1" />
                    </LinearGradientBrush>
                </Setter.Value>
            </Setter>
        </Style>

    </Page.Resources>
    <Grid>
        <StackPanel Orientation="Horizontal" Margin="50">
            <Button>A</Button>
            <Button>B</Button>
            <Button>C</Button>
            <Button>D</Button>
        </StackPanel>
    </Grid>
</Page>

==> learnwpfexercises/WpfDemos/WpfDemos/Templating.xaml <==
﻿<Page x:Class="WpfDemos.Templating"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
      xmlns:local="clr-namespace:WpfDemos"
      mc:Ignorable="d"
      d:DesignHeight="300"
      d:DesignWidth="300"
      Title="Templating">

    <WrapPanel Margin="10">
        <Button Content="Press me">
            <Button.Template>
                <ControlTemplate TargetType="{x:Type Button}">
                    <Ellipse Fill="GreenYellow"
                             Width="100"
                             Height="100" />
                </ControlTemplate>
            </Button.Template>
        </Button>
        <Border Width="10" />
        <Button Content="Press me">
            <Button.Template>
                <ControlTemplate TargetType="{x:Type Button}">
                    <Grid>
                        <Ellipse Fill="{TemplateBinding Background}"
                                 Width="100"
                                 Height="100" />
                        <Label Content="{TemplateBinding Content}"
                               HorizontalAlignment="Center"
                               VerticalAlignment="Center" />
                    </Grid>
                </ControlTemplate>
            </Button.Template>
        </Button>
    </WrapPanel>
</Page>
==> source/repos/BikeShop/BikeShop/App.xaml <==
﻿<Application x:Class="BikeShop.App"
             xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
             xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
             xmlns:local="clr-namespace:BikeShop"
             StartupUri="MainWindow.xaml">
    <Application.Resources>
        <LinearGradientBrush x:Key="background">
            <GradientStop Color="Aquamarine" Offset="0"/>
            <GradientStop Color="Violet" Offset="1"/>
        </LinearGradientBrush>
    </Application.Resources>
</Application>

==> source/repos/BikeShop/BikeShop/Contact.xaml <==
﻿<Page x:Class="BikeShop.Contact"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008" 
      xmlns:local="clr-namespace:BikeShop"
      mc:Ignorable="d" 
      d:DesignHeight="450" d:DesignWidth="800"
      Title="Contact" Background="{StaticResource background}">

    <Grid>
        <TextBlock HorizontalAlignment="Left" Margin="40,46,0,0" TextWrapping="Wrap" VerticalAlignment="Top" Height="18" Width="39"><Run Language="en-gb" Text="Sender"/></TextBlock>
        <TextBlock HorizontalAlignment="Left" Margin="40,87,0,0" TextWrapping="Wrap" VerticalAlignment="Top" Height="20" Width="50"><Run Language="en-gb" Text="Message"/></TextBlock>
        <TextBox HorizontalAlignment="Left" Margin="108,46,0,0" TextWrapping="Wrap" VerticalAlignment="Top" Width="634" Height="20"/>
        <TextBox HorizontalAlignment="Left" Margin="108,87,0,0" TextWrapping="Wrap" VerticalAlignment="Top" Width="634" Height="270"/>

    </Grid>
</Page>

==> source/repos/BikeShop/BikeShop/Discussion.xaml <==
﻿<Page x:Class="BikeShop.Discussion"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008" 
      xmlns:local="clr-namespace:BikeShop"
      mc:Ignorable="d" 
      d:DesignHeight="450" d:DesignWidth="800"
      Title="Discussion" Background="{StaticResource background}">
    <Grid>
        <Grid.ColumnDefinitions>
            <ColumnDefinition Width="*" />
            <ColumnDefinition Width="100" />
        </Grid.ColumnDefinitions>
        <Grid.RowDefinitions>
            <RowDefinition Height="*" />
            <RowDefinition Height="50" />
        </Grid.RowDefinitions>
        <ListBox Grid.ColumnSpan="2" Margin="5">
            <ListBox.ItemsSource>
                <local:Talk/>
            </ListBox.ItemsSource>
            <ListBox.ItemTemplate>
                <DataTemplate>
                    <StackPanel Width="300">
                        <StackPanel Orientation="Horizontal">
                            <Image Source="chat.png" Width="20"/>
                            <TextBlock Text="{Binding Sender}"/>
                        </StackPanel>
                        <TextBlock Text="{Binding Content}" Margin="20,0,0,0" TextWrapping="Wrap" />
                    </StackPanel>
                </DataTemplate>
            </ListBox.ItemTemplate>
        </ListBox>
        <Button Grid.Column="1" Grid.Row="1" Margin="5" Content="Send">
            <Button.Template>
                <ControlTemplate TargetType="Button">
                    <Grid>
                        <Ellipse Fill="#AA000000" Margin="10, 10, 0, 0"/>
                        <Ellipse Fill="{TemplateBinding Background}" Margin="0, 0, 10, 10"/>
                        <Viewbox Margin="5, 5, 15, 15">
                            <ContentPresenter/>
                        </Viewbox>
                    </Grid>
                </ControlTemplate>
            </Button.Template>
        </Button>
        <TextBox Grid.Row="1" Margin="5" Text="Type Your Message Here" />
    </Grid>
</Page>

==> source/repos/BikeShop/BikeShop/MainWindow.xaml <==
﻿<Window x:Class="BikeShop.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:BikeShop"
        mc:Ignorable="d"
        Title="MainWindow" Height="450" Width="800">
    <Grid>
        <Frame Source="/Menu.xaml"/>
    </Grid>
</Window>

==> source/repos/BikeShop/BikeShop/Menu.xaml <==
﻿<Page x:Class="BikeShop.Menu"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008" 
      xmlns:local="clr-namespace:BikeShop"
      mc:Ignorable="d" 
      d:DesignHeight="450" d:DesignWidth="800"
      Title="Menu"  Background="{StaticResource background}">
    <Page.Resources>
        <Style x:Key="menuButton" TargetType="Button">
            <Setter Property="Template">
                <Setter.Value>
                    <ControlTemplate TargetType="{x:Type Button}">
                        <Grid>
                            <Ellipse Width="233" Height="233" Fill="#AA000000" Margin="10, 10, 0, 0"/>
                            <Ellipse Width="233" Height="233" Fill="LightGray" Margin="0, 0, 10, 10"/>
                            <Viewbox Width="144" Height="144" HorizontalAlignment="Center" VerticalAlignment="Center">
                                <ContentPresenter HorizontalAlignment="Center" VerticalAlignment="Center"/>
                            </Viewbox>
                        </Grid>
                    </ControlTemplate>
                </Setter.Value>
            </Setter>
        </Style>
    </Page.Resources>
    <Grid>
        <Button Style="{StaticResource menuButton}" Content="Products" HorizontalAlignment="Left" Margin="284,42,0,0" VerticalAlignment="Top" Click="Button_Click_2" FontSize="12"/>
        <Button Style="{StaticResource menuButton}" Content="Live support" HorizontalAlignment="Left" Margin="10,42,0,0" VerticalAlignment="Top" Click="Button_Click_1" FontSize="12"/>
        <Button Style="{StaticResource menuButton}" Content="Email support" HorizontalAlignment="Left" Margin="547,42,0,0" VerticalAlignment="Top" FontSize="12" RenderTransformOrigin="4.22,-6.532" Click="Button_Click"/>
        <TextBlock HorizontalAlignment="Left" Height="77" Margin="208,316,0,0" Text="Adventure Works" TextWrapping="Wrap" VerticalAlignment="Top" Width="396" TextAlignment="Center" FontStyle="Italic" FontSize="48" FontWeight="Bold"/>
    </Grid>
</Page>

==> source/repos/BikeShop/BikeShop/ProductsManagement.xaml <==
﻿<Page x:Class="BikeShop.ProductsManagement"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008" 
      xmlns:local="clr-namespace:BikeShop"
      mc:Ignorable="d" 
      d:DesignHeight="450" d:DesignWidth="800"
      Title="ProductsManagement"  Background="{StaticResource background}">

    <Grid>
        <TextBox x:Name="textBox" HorizontalAlignment="Left" Margin="50,27,0,0" Text="" Background="white" TextWrapping="Wrap" VerticalAlignment="Top" Width="556" TextChanged="TextBox_TextChanged"/>
        <DataGrid Name="dataGrid" Margin="50,74,251,102"/>
        <Border DataContext="{Binding SelectedItem, ElementName=dataGrid}" Background="Lavender" BorderThickness="1" BorderBrush="Black" Margin="594,74,31,102">
            <StackPanel Margin="10">
                <TextBlock Text="Product details" FontSize="16" FontWeight="Bold" HorizontalAlignment="Center" Margin="10"/>
                <TextBlock Text="Title"/>
                <TextBox Text="{Binding Title, Mode=TwoWay}"/>
                <TextBlock Text="Price"/>
                <TextBox Text="{Binding Price, Mode=TwoWay}"/>
                <TextBlock Text="Color"/>
                <TextBox Text="{Binding Color, Mode=TwoWay}"/>
                <Border Background="{Binding Color}" Height="10"/>
                <TextBlock Text="Reference"/>
                <TextBox Text="{Binding Reference, Mode=TwoWay}"/>
            </StackPanel>
        </Border>
    </Grid>
</Page>

==> source/repos/CurrencyConverter/CurrencyConverter/App.xaml <==
﻿<Application x:Class="CurrencyConverter.App"
             xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
             xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
             xmlns:local="clr-namespace:CurrencyConverter"
             StartupUri="MainWindow.xaml">
    <Application.Resources>
         
    </Application.Resources>
</Application>

==> source/repos/CurrencyConverter/CurrencyConverter/MainWindow.xaml <==
﻿<Window x:Class="CurrencyConverter.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:CurrencyConverter"
        mc:Ignorable="d"
        Title="MainWindow" Height="250" Width="600" FontSize="18">
    <Window.DataContext>
        <local:CurrencyConverterViewModel/>
    </Window.DataContext>
    <Grid>
        <TextBlock HorizontalAlignment="Left" Margin="29,34,0,0" Text="Amount in €" TextWrapping="Wrap" VerticalAlignment="Top" FontSize="24"/>
        <TextBlock HorizontalAlignment="Left" Margin="29,0,0,0" Text="Amount in US $" TextWrapping="Wrap" VerticalAlignment="Center" FontSize="24"/>
        <TextBlock Text="{Binding _Dollars}" HorizontalAlignment="Left" Margin="209,0,0,0" TextWrapping="Wrap" VerticalAlignment="Center" RenderTransformOrigin="-0.12,0.526" FontSize="24" Width="353"/>
        <TextBox Text="{Binding _Euros}" HorizontalAlignment="Left" Margin="209,34,0,0" TextWrapping="Wrap" VerticalAlignment="Top" Width="353" TextBlock.FontSize="24"/>

    </Grid>
</Window>

==> source/repos/CurrencyConverter2/CurrencyConverter2/App.xaml <==
﻿<Application x:Class="CurrencyConverter2.App"
             xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
             xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
             xmlns:local="clr-namespace:CurrencyConverter2"
             StartupUri="MainWindow.xaml">
    <Application.Resources>
         
    </Application.Resources>
</Application>

==> source/repos/CurrencyConverter2/CurrencyConverter2/MainWindow.xaml <==
﻿<Window x:Class="CurrencyConverter2.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:CurrencyConverter2"
        mc:Ignorable="d"
        Title="MainWindow" Height="450" Width="800">
    <Window.DataContext>
        <local:CurrencyConverterViewModel/>
    </Window.DataContext>
    <Grid>
        <TextBlock HorizontalAlignment="Left" Margin="40,90,0,0" Text="Currency" TextWrapping="Wrap" VerticalAlignment="Top" Height="74" Width="163" FontSize="36"/>
        <TextBlock HorizontalAlignment="Left" Height="71" Margin="40,178,0,0" Text="Amount in €" TextWrapping="Wrap" VerticalAlignment="Top" Width="311" FontSize="36"/>
        <TextBlock HorizontalAlignment="Left" Height="63" Margin="40,284,0,0" Text="Amount in" TextWrapping="Wrap" VerticalAlignment="Top" Width="366" FontSize="36" RenderTransformOrigin="0.5,0.5">
            <TextBlock.RenderTransform>
                <TransformGroup>
                    <ScaleTransform/>
                    <SkewTransform AngleY="0.265"/>
                    <RotateTransform/>
                    <TranslateTransform Y="0.626"/>
                </TransformGroup>
            </TextBlock.RenderTransform>
        </TextBlock>
        <ComboBox HorizontalAlignment="Left" Margin="443,90,0,0" VerticalAlignment="Top" Width="319" Height="59" FontSize="36" SelectedItem="{Binding _SelectedCurrency}" ItemsSource="{Binding _Currencies}">
            <ComboBox.ItemTemplate>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
                <DataTemplate>
                    <TextBlock Text="{Binding _Title}"/>
                </DataTemplate>
            </ComboBox.ItemTemplate>
        </ComboBox>
        <TextBox HorizontalAlignment="Left" Margin="443,178,0,0" Text="{Binding _Euros}" TextWrapping="Wrap" VerticalAlignment="Top" Width="319" Height="59" FontSize="36"/>
        <TextBlock HorizontalAlignment="Left" Margin="443,285,0,0" Text="{Binding _ResultText}" TextWrapping="Wrap" VerticalAlignment="Top" FontSize="36" Width="319"/>
    </Grid>
</Window>

==> source/repos/HelloWPF/HelloWPF/App.xaml <==
﻿<Application x:Class="HelloWPF.App"
             xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
             xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
             xmlns:local="clr-namespace:HelloWPF"
             StartupUri="MainWindow.xaml">
    <Application.Resources>
         
    </Application.Resources>
</Application>

==> source/repos/HelloWPF/HelloWPF/MainWindow.xaml <==
﻿<Window x:Class="HelloWPF.MainWindow"
        xmlns="http://schemas.microsoft.c         2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:HelloWPF"
        mc:Ignorable="d"
        Title="MainWindow" Height="450" Width="800">
    <Grid>
        <Button Content="Say Hello" HorizontalAlignment="Left" Margin="338,163,0,0" VerticalAlignment="Top" Click="Button_Click"/>
        <TextBox x:Name="textBoxNew" HorizontalAlignment="Left" Margin="305,120,0,0" Text="TextBox" TextWrapping="Wrap" VerticalAlignment="Top" Width="120"/>

    </Grid>
</Window>

==> source/repos/Training_Videos/Training_Videos/App.xaml <==
﻿<Application x:Class="Training_Videos.App"
             xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
             xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
             xmlns:local="clr-namespace:Training_Videos"
             xmlns:converters="clr-namespace:Training_Videos.Converters"
             xmlns:componentModel="clr-namespace:System.ComponentModel;assembly=System.ComponentModel.TypeConverter"
             xmlns:model="clr-namespace:Training_Videos.Model"
             StartupUri="MainWindow.xaml">
    <Application.Resources>
        <DataTemplate x:Key="vehicleTemplate" DataType="model:IVehicle">
            <StackPanel Orientation="Horizontal">
                <Label Content="Make: "/>
                <Label Content="{Binding Make}" FontWeight="Bold"/>
                <Label Content="Model: "/>
                <Label Content="{Binding Model}" FontWeight="Bold"/>
                <Label Content="Wheels: "/>
                <Label Content="{Binding NumberOfWheels}" FontWeight="Bold"/>
                <Button Content="See Info"/>
            </StackPanel>
        </DataTemplate>
        <DataTemplate x:Key="planeTemplate" DataType="model:IPlane">
            <StackPanel Orientation="Horizontal">
                <Label Content="Make: "/>
                <Label Content="{Binding Make}" FontWeight="Bold"/>
                <Label Content="Model: "/>
                <Label Content="{Binding Model}" FontWeight="Bold"/>
                <Label Content="Wheels: "/>
                <Label Content="{Binding NumberOfWheels}" FontWeight="Bold"/>
                <Label Content="Wings: "/>
                <Label Content="{Binding numberOfWings}" FontWeight="Bold"/>
                <Button Content="See Info"/>
            </StackPanel>
        </DataTemplate>
        <DataTemplate x:Key="boatTemplate" DataType="model:IBoat">
            <StackPanel Orientation="Horizontal">
                <Label Content="Make: "/>
                <Label Content="{Binding Make}" FontWeight="Bold"/>
                <Label Content="Model: "/>
                <Label Content="{Binding Model}" FontWeight="Bold"/>
                <Label Content="Wheels: "/>
                <Label Content="{Binding NumberOfWheels}" FontWeight="Bold"/>
                <Label Content="Mast: "/>
                <Label Content="{Binding HasMast}" FontWeight="Bold"/>
                <Button Content="See Info"/>
            </StackPanel>
        </DataTemplate>
        <converters:DoubleRoundingConverter x:Key="DoubleRoundingConverter"/>
        <converters:DoubleToPostfixedStringConverter x:Key="DoubleToPostfixedStringConverter"/>
        <converters:MultipleBooleanToSingleBooleanAndConverter x:Key="MultipleBooleanToSingleBooleanAndConverter"></converters:MultipleBooleanToSingleBooleanAndConverter>
    </Application.Resources>
</Application>

==> source/repos/Training_Videos/Training_Videos/MainWindow.xaml <==
﻿<Window x:Class="Training_Videos.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:Training_Videos"
        xmlns:views="clr-namespace:Training_Videos.Views"
        xmlns:viewModels="clr-namespace:Training_Videos.ViewModels"
        mc:Ignorable="d"
        Title="MainWindow" Name="TestWindow" Height="900" Width="1150" 
        DataContext="{Binding RelativeSource={RelativeSource Self}}">
        <!--<Window.Resources>
        <BooleanToVisibilityConverter x:Key="BooleanToVisibilityConverter"/>
        <RoutedCommand x:Key="SayHelloCommand"/>
        <Style TargetType="Button">
            <Setter Property="Background" Value="Blue"/>
            <Setter Property="Foreground" Value="White"/>
        </Style>
        <Style x:Key="ButtonStyle" TargetType="Button">
            <Setter Property="HorizontalAlignment" Value="Center"/>
            <Setter Property="VerticalAlignment" Value="Center"/>
            <Setter Property="Background" Value="Red">
            </Setter>
            <Setter Property="Foreground" Value="White"/>
            <Setter Property="FontSize" Value="15"/>
            <Style.Triggers>
                <Trigger Property="IsMouseOver" Value="True">
                    <Setter Property="FontSize" Value="35"/>
                    <Setter Property="FontStyle" Value="Italic"/>
                </Trigger>
                <MultiTrigger>
                    <MultiTrigger.Conditions>
                        <Condition Property="IsPressed" Value="True"/>
                        <Condition Property="IsMouseOver" Value="True"/>
                    </MultiTrigger.Conditions>
                    <MultiTrigger.Setters>
                        <Setter Property="FontSize" Value="40"/>
                    </MultiTrigger.Setters>
                </MultiTrigger>
                <DataTrigger Binding="{Binding ElementName=newButton, Path=Content, UpdateSourceTrigger=PropertyChanged}" Value="Stan">
                    <Setter Property="FontSize" Value="50"></Setter>
                </DataTrigger>
                <Trigger Property="Content" Value="Fonz">
                    <Trigger.EnterActions>
                        <BeginStoryboard>
                            <Storyboard>
                                <Storyboard.Children>
                                    <DoubleAnimation 
                                        Storyboard.TargetProperty="FontSize" 
                                        From="18" To="50" 
                                        Duration="0:0:10"
                                        BeginTime="0:0:1"
                                        AutoReverse="True">
                                        <DoubleAnimation.EasingFunction>
                                            <ElasticEase Oscillations="5" Springiness="5"/>
                                        </DoubleAnimation.EasingFunction>
                                    </DoubleAnimation>
                                    <DoubleAnimation Storyboard.TargetProperty="Opacity" 
                                                     To="0" BeginTime="0:0:1" Duration="0:0:2.5"
                                                     AutoReverse="True"
                                                     RepeatBehavior="Forever"/>
                                    <ColorAnimation 
                                        Storyboard.TargetProperty="Background.Color" 
                                        To="Blue" BeginTime="0:0:0"
                                        Duration="0:0:0.5"
                                        AutoReverse="True"
                                        RepeatBehavior="Forever"/>
                                </Storyboard.Children>
                            </Storyboard>
                        </BeginStoryboard>
                    </Trigger.EnterActions>
                </Trigger>-->
                <!-- Overwhelms the former Databinding trigger -->
                <!--<EventTrigger RoutedEvent="MouseLeave">
                    <BeginStoryboard>
                        <Storyboard>
                            <Storyboard.Children>
                                <DoubleAnimation Storyboard.TargetProperty="Opacity"
                                                To="0" BeginTime="0:0:0"
                                                Duration="0:0:1" AutoReverse="True"></DoubleAnimation>
                                <DoubleAnimationUsingKeyFrames Storyboard.TargetProperty="FontSize" 
                                                                   BeginTime="0:0:0" Duration="0:0:10">
                                        <DoubleAnimationUsingKeyFrames.KeyFrames>
                                            <DiscreteDoubleKeyFrame KeyTime="0:0:2" Value="31"/>
                                            <DiscreteDoubleKeyFrame KeyTime="0:0:4" Value="27" />
                                            <DiscreteDoubleKeyFrame KeyTime="0:0:6" Value="23"/>
                                            <DiscreteDoubleKeyFrame KeyTime="0:0:8" Value="19"/>
                                            <DiscreteDoubleKeyFrame KeyTime="0:0:10" Value="15"/>
                                        </DoubleAnimationUsingKeyFrames.KeyFrames>
                                    </DoubleAnimationUsingKeyFrames>
                            </Storyboard.Children>
                        </Storyboard>
                    </BeginStoryboard>
                </EventTrigger>
            </Style.Triggers>
        </Style>
        <Style x:Key="DerivedButtonStyle" TargetType="Button" BasedOn="{StaticResource ButtonStyle}">
            <Setter Property="Background" Value="Blue"/>
        </Style>
    </Window.Resources>
    <Window.CommandBindings>
        <CommandBinding x:Name="SayHelloCommandBinding" Command="{StaticResource SayHelloCommand}" CanExecute="SayHelloCommandBinding_OnCanExecute" Executed="SayHelloCommandBinding_OnExecuted"/>
    </Window.CommandBindings>
    <Window.InputBindings>
        <KeyBinding Command="{StaticResource SayHelloCommand}" Key="H" Modifiers="Control"/>
        <KeyBinding Command="{StaticResource SayHelloCommand}" Gesture="Alt+Shift+H"/>
    </Window.InputBindings>
    <StackPanel Orientation="Vertical">
        <Canvas Width="500" Height="300" Background="AliceBlue">
            <Rectangle Width="50" Height="50" Fill="Black" Name="newRect"></Rectangle>
        </Canvas>-->
        <!--Below: Attached property is bound using round braces i.e. Rectangle inherits Canvas.Left, from Canvas as an attached property -->
        <!--<Slider Margin ="0,10,0,10" Minimum="0" Maximum ="450" Value="{Binding ElementName=newRect, Path=(Canvas.Left), Mode=TwoWay}"></Slider>
        <TextBox Grid.Column="0" Text="{Binding ElementName=TestWindow, Path=Width, Mode=TwoWay, UpdateSourceTrigger=LostFocus}"/>
        <Slider x:Name="newSlider" Grid.Column="1" Value="{Binding ElementName=TestWindow, Path=Width, Mode=TwoWay, UpdateSourceTrigger=Explicit}" Minimum="100" Maximum="1500"/>

        <TextBox Text="{Binding ElementName=TestWindow, Path=Height, Mode=TwoWay, UpdateSourceTrigger=LostFocus}"/>
        <Slider SmallChange="1" LargeChange="10"  Value="{Binding ElementName=TestWindow, Path=Height, Mode=TwoWay, UpdateSourceTrigger=PropertyChanged}" Minimum="100" Maximum="1500"/>
        <CheckBox/>
        <Slider Foreground="Black" Minimum="1" Maximum="50" TickFrequency="1" TickPlacement="BottomRight" >
            <Slider.Value>
                <Binding RelativeSource="{RelativeSource Self}" Path="TickFrequency" Mode="TwoWay"/>
            </Slider.Value>
        </Slider>
        <Button Style="{StaticResource DerivedButtonStyle}" Content="Update" Margin="10,30,10,0" Click="Button_Click"/>
        <TextBox Name="textBox1" Text="{Binding ElementName=Slider1, Path=Value, Converter={StaticResource DoubleRoundingConverter}}" Margin="0,30,0,0"></TextBox>
        <Slider Name="Slider1" SmallChange="0.001" LargeChange="0.2"  Margin="0,5,0,0" Minimum="0" Maximum="1" IsSnapToTickEnabled="True" TickFrequency="0.1" TickPlacement="BottomRight"></Slider>
        <TextBox Text="{Binding ElementName=textBox1, Path=Text, Converter={StaticResource DoubleToPostfixedStringConverter}, ConverterParameter=s}" Margin="0,5,0,0"></TextBox>
        <StackPanel Orientation="Horizontal" Margin="0,15,0,0">
            <CheckBox Content="Checkbox A" Foreground="Blue"  Name="A" Margin="15,0,0,0"/>
            <CheckBox Content="Checkbox B" Background="LightBlue" Name="B" Margin="15,0,0,0"/>
            <CheckBox Content="Checkbox C" VerticalContentAlignment="Center" Name="C" 
                      IsEnabled="False" Margin="15,0,0,0" Foreground="Red">
                <CheckBox.IsChecked>
                    <MultiBinding Converter="{StaticResource MultipleBooleanToSingleBooleanAndConverter}">
                        <MultiBinding.Bindings>
                            <Binding ElementName="A" Path="IsChecked" Mode="OneWay"></Binding>
                            <Binding ElementName="B" Path="IsChecked" Mode="OneWay"></Binding>
                        </MultiBinding.Bindings>
                    </MultiBinding>
                </CheckBox.IsChecked>
                <CheckBox.Template>
                    <ControlTemplate TargetType="CheckBox">
                        <Grid>
                            <Grid.ColumnDefinitions>
                                <ColumnDefinition Width="Auto"/>
                                <ColumnDefinition Width="Auto"/>
                            </Grid.ColumnDefinitions>
                            <Border BorderThickness="2" Focusable="True"  
                                    BorderBrush="{TemplateBinding Foreground}" Width="50" Height="50">
                                <Path Data="M8,25 l12,12 l22,-32" Stroke="{TemplateBinding Foreground}"
                                      StrokeThickness="8" Name="NewTick" Visibility="Hidden"/>
                            </Border>
                            <Label Content="{TemplateBinding Content}"
                                   VerticalAlignment="{TemplateBinding VerticalContentAlignment}"
                                   Grid.Column="1" Foreground="{TemplateBinding Foreground}"/>
                        </Grid>
                        <ControlTemplate.Triggers>
                            <DataTrigger Value="True" 
                                         Binding="{Binding ElementName=C, Path=IsChecked}">
                                <Setter TargetName="NewTick" Property="Visibility" Value="Visible"/>
                            </DataTrigger>
                            <DataTrigger Value="False" 
                                         Binding="{Binding ElementName=C, Path=IsChecked}">
                                <Setter TargetName="NewTick" Property="Visibility" Value="Hidden"/>
                            </DataTrigger>
                        </ControlTemplate.Triggers>
                    </ControlTemplate>
                </CheckBox.Template>
            </CheckBox>
            <CheckBox Content="Checkbox D" VerticalContentAlignment="Center"
                      Margin="15,0,0,0" Foreground="Blue">
                <CheckBox.Template>
                    <ControlTemplate TargetType="CheckBox">
                        <Grid>
                            <Grid.ColumnDefinitions>
                                <ColumnDefinition Width="Auto"/>
                                <ColumnDefinition Width="Auto"/>
                            </Grid.ColumnDefinitions>
                            <Path Data="M8,25 l12,12 l22,-32" Stroke="{TemplateBinding Foreground}"
                                      StrokeThickness="8" Name="ThisTick" Focusable="True"
                                      Visibility="{TemplateBinding IsChecked, Converter={StaticResource BooleanToVisibilityConverter}}"/>
                            <Label Content="{TemplateBinding Content}"
                                   VerticalAlignment="{TemplateBinding VerticalContentAlignment}"
                                   Grid.Column="1" Foreground="{TemplateBinding Foreground}"/>
                        </Grid>
                    </ControlTemplate>
                </CheckBox.Template>
            </CheckBox>
        </StackPanel>
        <Button Content="newButton" Command="{StaticResource SayHelloCommand}" CommandParameter="world!"/>
        <Label Name="newLabel" Margin="0,15,0,0">

        </Label>
        <TextBox x:Name="Newtext" Margin="0,10,0,0">
            <TextBox.CommandBindings>
                <CommandBinding Command="Paste" x:Name="PasteIntoLabelCommandBindingExecuted" Executed="PasteIntoLabelCommandBindingExecuted_OnExecuted"></CommandBinding>
            </TextBox.CommandBindings>
            <TextBox.InputBindings>
                <KeyBinding Command="Paste" Key="L" Modifiers="Control"></KeyBinding>
            </TextBox.InputBindings>
        </TextBox>
        <Button Content="Switch message" Margin="0,10,0,0"
                DataContext="{Binding RelativeSource={RelativeSource Mode=FindAncestor, AncestorType=local:MainWindow}}"  
                Command="{Binding NewHelloCommand}"
                CommandParameter="{Binding}"
                />
        <Button x:Name="newButton" Content="{Binding Text, ElementName=Newtext, UpdateSourceTrigger=PropertyChanged}" 
                Margin="0,10,0,0" 
                Command="{Binding NewHelloCommand}"
                CommandParameter="{Binding Text, ElementName=Newtext, UpdateSourceTrigger=PropertyChanged}"
                Style="{StaticResource ButtonStyle}"
                />
    </StackPanel>-->
    <!-- Syntax for a control
    <views:MainView>
        <views:MainView.ViewModel>
            <viewModels:MainViewModel/>
        </views:MainView.ViewModel>
    </views:MainView>-->
    <Grid>
        <Frame Source="/Views//MainView.xaml"/>
    </Grid>
</Window>
    
    

==> source/repos/Training_Videos/Training_Videos/Views/MainView.xaml <==
﻿<Page x:Class="Training_Videos.Views.MainView"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008" 
      xmlns:local="clr-namespace:Training_Videos.Views"
      xmlns:designViewModels="clr-namespace:Training_Videos.DesignViewModels"
      xmlns:model="clr-namespace:Training_Videos.Model"
      xmlns:templateSelector="clr-namespace:Training_Videos.TemplateSelector"
      mc:Ignorable="d" 
      d:DesignHeight="450" d:DesignWidth="800"
      Title="MainView" d:DataContext="{d:DesignInstance d:IsDesignTimeCreatable=True, Type={x:Type designViewModels:MainDesignViewModel}}">
    <Page.Resources>
        <templateSelector:VehicleTemplateSelector x:Key="VehicleTemplateSelector"></templateSelector:VehicleTemplateSelector>
    </Page.Resources>
    <Grid>
        <!--<Label DataContext="" Content="{Binding Path=Map.Name, Mode=OneWay}"></L abel>-->
        <ListBox ItemsSource="{Binding vehicles}" ItemTemplateSelector="{StaticResource VehicleTemplateSelector}"/>
    </Grid>
</Page>

==> source/repos/WpfAppBinding/WpfAppBinding/App.xaml <==
﻿<Application x:Class="WpfAppBinding.App"
             xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
             xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
             xmlns:local="clr-namespace:WpfAppBinding"
             StartupUri="MainWindow.xaml">
    <Application.Resources>
    </Application.Resources>
</Application>

==> source/repos/WpfAppBinding/WpfAppBinding/MainWindow.xaml <==
﻿<Window x:Class="WpfAppBinding.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:WpfAppBinding"
        xmlns:new="clr-namespace:System;assembly=mscorlib" xmlns:sys="clr-namespace:System;assembly=System.Runtime"
        mc:Ignorable="d"
        Title="MainWindow" Height="600" Width="1080"
        Background="{Binding Text, ElementName=color}">
    <Window.Resources>
        <sys:String x:Key="emailRegex">
            ^[a-zA-Z][\w\.-]*[a-zA-Z0-9]@[a-zA-Z0-9][\w\.-]*a-zA-Z0-9]\.[a-zA-Z][a-zA-Z\.]*[a-zA-Z]$
        </sys:String>
        <local:BoolToStringConverter x:Key="bool2String"/>
        <local:Classroom x:Key="Students"/>           
        <ObjectDataProvider x:Key="alignments" MethodName="GetNames" ObjectType="{x:Type new:Enum}">
            <ObjectDataProvider.MethodParameters>
                <x:Type TypeName="VerticalAlignment" />
            </ObjectDataProvider.MethodParameters>
        </ObjectDataProvider>
        <Style x:Key="myStyle" TargetType="Button">
            <Setter Property="Background" Value="Orange"/>
            <Setter Property="FontStyle" Value="Italic"/>
            <Setter Property="Padding" Value="3,4"/>
            <Setter Property="Margin" Value="4"/>
        </Style>
        <Style x:Key="boldStyle" TargetType="Button" BasedOn="{StaticResource myStyle}">
            <Setter Property="FontWeight" Value="ExtraBold"/>
        </Style>
        <Style x:Key="DialogButtonStyle" TargetType="Button">
            <Style.Triggers>
                <Trigger Property="IsMouseOver" Value="True">
                    <Setter Property="Background" Value="LightGreen"/>
                </Trigger>
            </Style.Triggers>
            <Setter Property="Template">
                <Setter.Value>
                    <ControlTemplate TargetType="{x:Type Button}">
                        <Grid>
                            <Ellipse Fill="{TemplateBinding Background}"
                                     Stroke="{TemplateBinding BorderBrush}"/>
                            <ContentPresenter HorizontalAlignment="Center"
                                                       VerticalAlignment="Center" />
                        </Grid> 
                    </ControlTemplate>
                </Setter.Value>
            </Setter>
        </Style>
        <Style x:Key="EmailError" TargetType="TextBox">
            <Style.Triggers>
                <DataTrigger Binding="{Binding Path=Validation.HasError}" Value="True">
                    <Setter Property="Template">
                        <Setter.Value>
                            <ControlTemplate x:Name="EmailBoxError" TargetType="Control">
                                <Grid ClipToBounds="False">
                                    <Image HorizontalAlignment="Right" VerticalAlignment="Top" Width="16" Height="16"
                    Margin="0,-8,-8,0" 
                    ToolTip="{Binding ElementName=adornedElement, 
                            Path=AdornedElement.(Validation.Errors),
                            Converter={local:ValidationErrorsToStringConverter}}"/>
                                    <Border BorderBrush="Red" BorderThickness="1" Margin="-1">
                                        <AdornedElementPlaceholder Name="adornedElement" />
                                    </Border>
                                </Grid>
                            </ControlTemplate>
                        </Setter.Value>
                    </Setter>
                </DataTrigger>
            </Style.Triggers>
        </Style>

        <Style x:Key="styleWithTrigger" TargetType="Rectangle">
            <Setter Property="Fill" Value="LightGray" />
            <Style.Triggers>
                <Trigger Property="IsMouseOver" Value="True">
                    <Setter Property="Fill" Value="Green"/>
                </Trigger>
            </Style.Triggers>
        </Style>
        <Style x:Key="niceButton" TargetType="Button">
            <Setter Property="Width" Value="50"/>
            <Setter Property="Height" Value="50"/>
            <Setter Property="Background">
                <Setter.Value>
                    <LinearGradientBrush>
                        <GradientStop Color="Red" Offset="0"/>
                        <GradientStop Color="Yellow" Offset="1"/>
                    </LinearGradientBrush>
                </Setter.Value>
            </Setter>
        </Style>
    </Window.Resources>
    <Grid RenderTransformOrigin="0.392,0.436">
        <TextBox x:Name="txtInput" HorizontalAlignment="Left" Margin="654,309,0,0" Text="'ello&#xD;&#xA;" TextWrapping="Wrap" VerticalAlignment="Top" Width="120"/>
        <Label Content="{Binding Text, ElementName=txtInput, UpdateSourceTrigger=PropertyChanged}" HorizontalAlignment="Left" Height="42" Margin="664,343,0,0" VerticalAlignment="Top" Width="72" RenderTransformOrigin="0.229,-0.293"/>
        <StackPanel Margin="58,41,10,165">
            <StackPanel.Resources>
                <BooleanToVisibilityConverter x:Key="bool2Vis"/>
            </StackPanel.Resources>
            <CheckBox x:Name="chkShowDetails" Content="Show details"/>
            <StackPanel x:Name="detailsPanel"  Visibility="{Binding IsChecked, Converter={StaticResource bool2Vis}, ElementName=chkShowDetails}" HorizontalAlignment="Left" Height="42" Margin="536,120,0,0" VerticalAlignment="Top" Width="72" RenderTransformOrigin="0.229,-0.293">
                <Label Content="Hey yo" RenderTransformOrigin="-3.622,-3.467"/>
            </StackPanel>
        </StackPanel>
        <Label Content="{Binding IsChecked, Converter={StaticResource bool2String}, ElementName=chkShowDetails}" HorizontalAlignment="Left" Margin="87,248,0,0" VerticalAlignment="Top" Height="42" Width="138"/>
        <ComboBox ItemsSource="{Binding Source={StaticResource alignments}}" HorizontalAlignment="Left" Margin="87,274,0,0" VerticalAlignment="Top" Width="120"/>
        <Button Content="Unstyled Button" HorizontalAlignment="Left" Margin="89,358,0,0" VerticalAlignment="Top"/>
        <Button Style="{StaticResource myStyle}" Content="Styled Button 1" HorizontalAlignment="Left" Margin="184,355,0,0" VerticalAlignment="Top"/>
        <Button Style="{StaticResource boldStyle}" Content="Styled Button 2" HorizontalAlignment="Left" Margin="281,355,0,0" VerticalAlignment="Top"/>
        <Rectangle Style="{StaticResource styleWithTrigger}" HorizontalAlignment="Left" Height="23" Margin="400,355,0,0" Stroke="Black" VerticalAlignment="Top" Width="100"/>
        <Button Style="{StaticResource DialogButtonStyle}" Content="Button" HorizontalAlignment="Left" Margin="515,355,0,0" VerticalAlignment="Top" Height="23" Width="54"/>
        <TextBox x:Name="txtEMail" Style="{StaticResource EmailError}" HorizontalAlignment="Left" Margin="398,309,0,0" TextWrapping="Wrap" VerticalAlignment="Top" Width="142" Height="34" xml:space="preserve">knkn  n;kn</TextBox>
        <TextBox x:Name="color" Background="{Binding Text}" HorizontalAlignment="Left" Margin="89,401,0,0" Text="White" TextWrapping="Wrap" VerticalAlignment="Top" Width="120"/>
        <ListBox ItemsSource="{Binding Students}" Margin="74,438,168,10">
            <TextBlock Text="{Binding _names}" />
        </ListBox>
        <Button Style="{StaticResource niceButton}" Content="Button" HorizontalAlignment="Left" Margin="969,438,0,0" VerticalAlignment="Top"/>
    </Grid>
</Window>
