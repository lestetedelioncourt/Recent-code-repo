==> ./amazon-locators/Resources/AmazonApp.robot <==
*** Settings ***
Resource  ../Resources/PO/LandingPage.robot
Resource  ../Resources/PO/TopNav.robot
Resource  ../Resources/PO/SearchResults.robot
Resource  ../Resources/PO/Product.robot
Resource  ../Resources/PO/Cart.robot
Resource  ../Resources/PO/SignIn.robot

*** Keywords ***
Login
    [Arguments]  ${Username}  ${Password}
    SignIn.Login With Valid Credentials    ${Username}  ${Password}

Login with Invalid Credentials
    SignIn.Fill "Email" Field  bogus@bogus.com
    SignIn.Fill "Password" Field  badPassword
    SignIn.Click "Sign In" Button

Search for Products
    [Arguments]  ${SearchTerm}
    LandingPage.Load
    LandingPage.Verify Page Loaded
    TopNav.Search for Products    ${SearchTerm}
    SearchResults.Verify Search Completed  ${SearchTerm}

Verify Results Page Contains Products
    [Arguments]  ${ExpectedProductCount}
    SearchResults.Verify Product Count  ${ExpectedProductCount}

Select Product from Search Results
    SearchResults.Click Product link
    Product.Verify Page Loaded

Add Product to Cart
    Product.Add to Cart
    Cart.Verify Product Added

Begin Checkout
    Cart.Proceed to Checkout
    SignIn.Verify Page Loaded
==> ./amazon-locators/Resources/Common.robot <==
*** Settings ***
Library  Selenium2Library

*** Variables ***

*** Keywords ***
Begin Web Test
    Open Browser  about:blank  ${BROWSER}
    # Maximize Browser Window

End Web Test
    Close Browser
==> ./amazon-locators/Resources/PO/Cart.robot <==
*** Settings ***
Library  Selenium2Library

*** Keywords ***
Verify Product Added
    Wait Until Page Contains  subtotal

Proceed to Checkout
    Click Link  id=hlb-ptc-btn-native
==> ./amazon-locators/Resources/PO/LandingPage.robot <==
*** Settings ***
Library  Selenium2Library

*** Variables ***


*** Keywords ***
Load
    Go To  ${START_URL}

Verify Page Loaded
    Wait Until Page Contains  Today's Deals
==> ./amazon-locators/Resources/PO/Product.robot <==
*** Settings ***
Library  Selenium2Library

*** Keywords ***
Verify Page Loaded
    Wait Until Page Contains  Back to search results

Add to Cart
    Click Button  id=add-to-cart-button
==> ./amazon-locators/Resources/PO/SearchResults.robot <==
*** Settings ***
Library  Selenium2Library

*** Keywords ***
Verify Search Completed
    [Arguments]  ${SearchTerm}
    Wait Until Page Contains  ${SearchTerm}

Verify Product Count
    [Arguments]  ${ExpectedProductCount}
    xpath should match x times  //li[contains(@id, "result_")]  ${ExpectedProductCount}

Click Product Link
    [Documentation]  Clicks on the first product in the search results list
    Click Link  css=#result_0 a.s-access-detail-page
==> ./amazon-locators/Resources/PO/SignIn.robot <==
*** Settings ***
Library  Selenium2Library

*** Variables ***
${SIGNIN_MAIN_HEADING} =  xpath=//h2

*** Keywords ***
Verify Page Loaded
    Page Should Contain Element     ${SIGNIN_MAIN_HEADING}
    Element Text Should Be          ${SIGNIN_MAIN_HEADING}  Sign In

Login With Valid Credentials
    [Arguments]  ${Username}  ${Password}
    Fill "Email" Field  ${Username}
    Fill "Password" Field  ${Password}
    Click "Sign In" Button

Fill "Email" Field
    [Arguments]  ${Username}
    Log  Filling Email field with ${Username}

Fill "Password" Field
    [Arguments]  ${Password}
    Log  Filling Password field with ${Password}

Click "Sign In" Button
    Log  Clicking submit button
==> ./amazon-locators/Resources/PO/TopNav.robot <==
*** Settings ***
Documentation  Amazon top navigation
Library  Selenium2Library

*** Variables ***
${TOPNAV_SEARCH_BAR} =      id=twotabsearchtextbox
${TOPNAV_SEARCH_BUTTON} =   xpath=//*[@id="nav-search-submit-button"]

*** Keywords ***
Search for Products
    [Arguments]  ${SearchTerm}
    Enter Search Term  ${SearchTerm}
    Submit Search

Enter Search Term
    [Arguments]  ${SearchTerm}
    Input Text  ${TOPNAV_SEARCH_BAR}  ${SearchTerm}

Submit Search
    Click Button  ${TOPNAV_SEARCH_BUTTON}

==> ./amazon-locators/Tests/Amazon.robot <==
*** Settings ***
Documentation  This is some basic info about the whole suite
Resource  ../Resources/Common.robot  # for Setup & Teardown
Resource  ../Resources/AmazonApp.robot  # for lower level keywords in test cases
Test Setup  Common.Begin Web Test
Test Teardown  Common.End Web Test

# pybot -d results -i current tests/Amazon.robot

*** Variables ***
${BROWSER} =  chrome
${START_URL} =  https://www.amazon.com
${SEARCH_TERM} =  Ferrari 458
${LOGIN_EMAIL} =  admin@robotrameworktutorial.com
${LOGIN_PASSWORD} =  myPassword1

*** Test Cases ***
Should be able to login
    [Tags]  Login
    AmazonApp.Login  ${LOGIN_EMAIL}  ${LOGIN_PASSWORD}

Logged out user should be able to search for products
    [Tags]  search
    AmazonApp.Search for Products  ${SEARCH_TERM}

Search results page should contain 30 products
    [Tags]  Current
    AmazonApp.Search for Products  ${SEARCH_TERM}
    AmazonApp.Verify Results Page Contains Products  30

Logged out user should be able to view a product
    AmazonApp.Search for Products  ${SEARCH_TERM}
    AmazonApp.Select Product from Search Results

Logged out user should be able to add product to cart
    AmazonApp.Search for Products  ${SEARCH_TERM}
    AmazonApp.Select Product from Search Results
    AmazonApp.Add Product to Cart

Logged out user should be asked to sign in to check out
    AmazonApp.Search for Products  ${SEARCH_TERM}
    AmazonApp.Select Product from Search Results
    AmazonApp.Add Product to Cart
    AmazonApp.Begin Checkout

==> ./end-to-end/Data/InputData.robot <==
*** Variables ***
${BROWSER} =  edge
${FRONT_OFFICE_URL} =  http://www.robotframeworktutorial.com/front-office
${BACK_OFFICE_URL} =  http://www.robotframeworktutorial.com/back-office

==> ./end-to-end/Resources/BackOffice/BackOfficeApp.robot <==
*** Settings ***
Resource  ./PO/BackOffice.Landing.robot
Resource  ./PO/TopNav.robot

*** Variables ***


*** Keywords ***
Go to Landing Page
    BackOffice.Landing.Navigate To
    #Landing.Verify Page Loaded


==> ./end-to-end/Resources/BackOffice/PO/BackOffice.Landing.robot <==
*** Settings ***
Library  Selenium2Library

*** Variables ***
${LANDING_NAVIGATION_ELEMENT} =  id=mainNav

*** Keywords ***
Navigate To
    go to  ${BACK_OFFICE_URL}

Verify Page Loaded
    wait until page contains element  ${LANDING_NAVIGATION_ELEMENT}
==> ./end-to-end/Resources/BackOffice/PO/TopNav.robot <==
*** Settings ***
Library  Selenium2Library

*** Variables ***
${TOP_NAV_TEAM_LINK} =  css=#bs-example-navbar-collapse-1 > ul > li:nth-child(5) > a

*** Keywords ***
Select "Team" Page
    click element  ${TOP_NAV_TEAM_LINK}
    Sleep  3s
==> ./end-to-end/Resources/Common/CommonWeb.robot <==
*** Settings ***
Library  Selenium2Library

*** Variables ***


*** Keywords ***
Begin Web Test
    open browser  about:blank  ${BROWSER}
    #maximize browser window

End Web Test
    close all browsers
==> ./end-to-end/Resources/FrontOffice/FrontOfficeApp.robot <==
*** Settings ***
Resource  ./PO/FrontOffice.Landing.robot
Resource  ./PO/TopNav.robot
Resource  ./PO/Team.robot

*** Variables ***


*** Keywords ***
Go to Landing Page
    FrontOffice.Landing.Navigate To
    FrontOffice.Landing.Verify Page Loaded

Go to "Team" Page
    TopNav.Select "Team" Page
    Team.Verify Page Loaded

Validate "Team" Page
    Team.Validate Page Contents
==> ./end-to-end/Resources/FrontOffice/PO/FrontOffice.Landing.robot <==
*** Settings ***
Library  Selenium2Library

*** Variables ***
${LANDING_NAVIGATION_ELEMENT} =  id=mainNav

*** Keywords ***
Navigate To
    go to  ${FRONT_OFFICE_URL}

Verify Page Loaded
    wait until page contains element  ${LANDING_NAVIGATION_ELEMENT}
==> ./end-to-end/Resources/FrontOffice/PO/Team.robot <==
*** Settings ***
Library  Selenium2Library

*** Variables ***
${TEAM_HEADER_LABEL} =  css=#team > div > div:nth-child(1) > div > h2

*** Keywords ***
Verify Page Loaded
    wait until page contains element  ${TEAM_HEADER_LABEL}

Validate Page Contents
    # this fails in chrome but passes in Edge
    #element text should be  ${TEAM_HEADER_LABEL}  Our Amazing Team

    ${ElementText} =  get text  ${TEAM_HEADER_LABEL}
    should be equal as strings  ${ElementText}  Our Amazing Team  ignore_case=true

==> ./end-to-end/Resources/FrontOffice/PO/TopNav.robot <==
*** Settings ***
Library  Selenium2Library

*** Variables ***
${TOP_NAV_TEAM_LINK} =  css=#bs-example-navbar-collapse-1 > ul > li:nth-child(5) > a

*** Keywords ***
Select "Team" Page
    click element  ${TOP_NAV_TEAM_LINK}
    Sleep  3s
==> ./end-to-end/Tests/BackOffice/Back_Office.robot <==
*** Settings ***
Documentation  Talk about what this suite of tests does
Resource  ../../Data/InputData.robot
Resource  ../../Resources/BackOffice/BackOfficeApp.robot
Resource  ../../Resources/Common/CommonWeb.robot
Test Setup  Begin Web Test
Test Teardown  End Web Test

# robot -d results tests/BackOffice/Back_Office.robot

*** Test Cases ***
Should be able to access "Landing" page
    [Documentation]  This is test 1
    [Tags]  test1
    BackOfficeApp.Go to Landing Page



==> ./end-to-end/Tests/EndToEnd/End_to_End.robot <==
*** Settings ***
Documentation  This is my end to end suite
Resource  ../../Data/InputData.robot
Resource  ../../Resources/FrontOffice/FrontOfficeApp.robot
Resource  ../../Resources/BackOffice/BackOfficeApp.robot
Resource  ../../Resources/Common/CommonWeb.robot
Test Setup  Begin Web Test
Test Teardown  End Web Test

# robot -d results tests/EndToEnd/End_to_End.robot

*** Test Cases ***
Should be able to access both sites
    [Documentation]  This is test 1
    [Tags]  test1
    FrontOfficeApp.Go to Landing Page
    BackOfficeApp.Go to Landing Page



==> ./end-to-end/Tests/FrontOffice/Front_Office.robot <==
*** Settings ***
Documentation  Talk about what this suite of tests does
Resource  ../../Data/InputData.robot
Resource  ../../Resources/FrontOffice/FrontOfficeApp.robot
Resource  ../../Resources/Common/CommonWeb.robot
Test Setup  Begin Web Test
Test Teardown  End Web Test

# robot -d results tests/FrontOffice/Front_Office.robot

*** Test Cases ***
Should be able to access "Team" page
    [Documentation]  This is test 1
    [Tags]  test1
    FrontOfficeApp.Go to Landing Page
    FrontOfficeApp.Go to "Team" Page

"Team" page should match requirements
    [Documentation]  This is test 2
    [Tags]  test2
    FrontOfficeApp.Go to Landing Page
    FrontOfficeApp.Go to "Team" Page
    FrontOfficeApp.Validate "Team" Page
==> ./input-data-end/end-to-end/Data/InputData.robot <==
*** Variables ***
${BROWSER} =  edge
${FRONT_OFFICE_URL} =  http://www.robotframeworktutorial.com/front-office
${BACK_OFFICE_URL} =  http://www.robotframeworktutorial.com/back-office

==> ./input-data-end/end-to-end/Resources/BackOffice/BackOfficeApp.robot <==
*** Settings ***
Resource  ./PO/BackOffice.Landing.robot
Resource  ./PO/TopNav.robot

*** Variables ***


*** Keywords ***
Go to Landing Page
    BackOffice.Landing.Navigate To
    #Landing.Verify Page Loaded


==> ./input-data-end/end-to-end/Resources/BackOffice/PO/BackOffice.Landing.robot <==
*** Settings ***
Library  Selenium2Library

*** Variables ***
${LANDING_NAVIGATION_ELEMENT} =  id=mainNav

*** Keywords ***
Navigate To
    go to  ${BACK_OFFICE_URL}

Verify Page Loaded
    wait until page contains element  ${LANDING_NAVIGATION_ELEMENT}
==> ./input-data-end/end-to-end/Resources/BackOffice/PO/TopNav.robot <==
*** Settings ***
Library  Selenium2Library

*** Variables ***
${TOP_NAV_TEAM_LINK} =  css=#bs-example-navbar-collapse-1 > ul > li:nth-child(5) > a

*** Keywords ***
Select "Team" Page
    click element  ${TOP_NAV_TEAM_LINK}
    Sleep  3s
==> ./input-data-end/end-to-end/Resources/Common/CommonWeb.robot <==
*** Settings ***
Library  Selenium2Library

*** Variables ***


*** Keywords ***
Begin Web Test
    open browser  about:blank  ${BROWSER}
    #maximize browser window

End Web Test
    close all browsers
==> ./input-data-end/end-to-end/Resources/FrontOffice/FrontOfficeApp.robot <==
*** Settings ***
Resource  ./PO/FrontOffice.Landing.robot
Resource  ./PO/TopNav.robot
Resource  ./PO/Team.robot

*** Variables ***


*** Keywords ***
Go to Landing Page
    FrontOffice.Landing.Navigate To
    FrontOffice.Landing.Verify Page Loaded

Go to "Team" Page
    TopNav.Select "Team" Page
    Team.Verify Page Loaded

Validate "Team" Page
    Team.Validate Page Contents
==> ./input-data-end/end-to-end/Resources/FrontOffice/PO/FrontOffice.Landing.robot <==
*** Settings ***
Library  Selenium2Library

*** Variables ***
${LANDING_NAVIGATION_ELEMENT} =  id=mainNav

*** Keywords ***
Navigate To
    go to  ${FRONT_OFFICE_URL}

Verify Page Loaded
    wait until page contains element  ${LANDING_NAVIGATION_ELEMENT}
==> ./input-data-end/end-to-end/Resources/FrontOffice/PO/Team.robot <==
*** Settings ***
Library  Selenium2Library

*** Variables ***
${TEAM_HEADER_LABEL} =  css=#team > div > div:nth-child(1) > div > h2

*** Keywords ***
Verify Page Loaded
    wait until page contains element  ${TEAM_HEADER_LABEL}

Validate Page Contents
    # this fails in chrome but passes in Edge
    #element text should be  ${TEAM_HEADER_LABEL}  Our Amazing Team

    ${ElementText} =  get text  ${TEAM_HEADER_LABEL}
    should be equal as strings  ${ElementText}  Our Amazing Team  ignore_case=true

==> ./input-data-end/end-to-end/Resources/FrontOffice/PO/TopNav.robot <==
*** Settings ***
Library  Selenium2Library

*** Variables ***
${TOP_NAV_TEAM_LINK} =  css=#bs-example-navbar-collapse-1 > ul > li:nth-child(5) > a

*** Keywords ***
Select "Team" Page
    click element  ${TOP_NAV_TEAM_LINK}
    Sleep  3s
==> ./input-data-end/end-to-end/Tests/BackOffice/Back_Office.robot <==
*** Settings ***
Documentation  Talk about what this suite of tests does
Resource  ../../Data/InputData.robot
Resource  ../../Resources/BackOffice/BackOfficeApp.robot
Resource  ../../Resources/Common/CommonWeb.robot
Test Setup  Begin Web Test
Test Teardown  End Web Test

# robot -d results tests/BackOffice/Back_Office.robot

*** Test Cases ***
Should be able to access "Landing" page
    [Documentation]  This is test 1
    [Tags]  test1
    BackOfficeApp.Go to Landing Page



==> ./input-data-end/end-to-end/Tests/EndToEnd/End_to_End.robot <==
*** Settings ***
Documentation  This is my end to end suite
Resource  ../../Data/InputData.robot
Resource  ../../Resources/FrontOffice/FrontOfficeApp.robot
Resource  ../../Resources/BackOffice/BackOfficeApp.robot
Resource  ../../Resources/Common/CommonWeb.robot
Test Setup  Begin Web Test
Test Teardown  End Web Test

# robot -d results tests/EndToEnd/End_to_End.robot

*** Test Cases ***
Should be able to access both sites
    [Documentation]  This is test 1
    [Tags]  test1
    FrontOfficeApp.Go to Landing Page
    BackOfficeApp.Go to Landing Page



==> ./input-data-end/end-to-end/Tests/FrontOffice/Front_Office.robot <==
*** Settings ***
Documentation  Talk about what this suite of tests does
Resource  ../../Data/InputData.robot
Resource  ../../Resources/FrontOffice/FrontOfficeApp.robot
Resource  ../../Resources/Common/CommonWeb.robot
Test Setup  Begin Web Test
Test Teardown  End Web Test

# robot -d results tests/FrontOffice/Front_Office.robot

*** Test Cases ***
Should be able to access "Team" page
    [Documentation]  This is test 1
    [Tags]  test1
    FrontOfficeApp.Go to Landing Page
    FrontOfficeApp.Go to "Team" Page

"Team" page should match requirements
    [Documentation]  This is test 2
    [Tags]  test2
    FrontOfficeApp.Go to Landing Page
    FrontOfficeApp.Go to "Team" Page
    FrontOfficeApp.Validate "Team" Page
