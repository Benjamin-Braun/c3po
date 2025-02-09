#include "main.h"

struct CarStruct {
    int scale;
    string title;
    string button;
    string folder;
    string credits;
};

CarStruct vwCars[] = {
    {100, "Volkswagen Golf GTI (1992)", "Load Golf 1992", "1992_gti", "This work is based on \"1992 Volkswagen Golf GTI Mk2\" (https://sketchfab.com/3d-models/1992-volkswagen-golf-gti-mk2-1fb8f26b105445fbaa98ca2577f7067e) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {100, "Volkswagen Golf GTI (2014)", "Load Golf 2014", "2014_gti", "This work is based on \"2014 Volkswagen Golf GTI Mk7\" (https://sketchfab.com/3d-models/2014-volkswagen-golf-gti-mk7-93f2b79c56c14b269fbe914205c4712e) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {1, "Volkswagen Jetta (2019)", "Load Jetta", "jetta", "This work is based on \"2019 Volkswagen Jetta\" (https://sketchfab.com/3d-models/2019-volkswagen-jetta-c9031d4501f74639a2552539fd2dba36) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {100, "Volkswagen Polo R WRC (2015)", "Load Polo WRC", "polo_wrc", "This work is based on \"2015 Volkswagen Polo R WRC\" (https://sketchfab.com/3d-models/2015-volkswagen-polo-r-wrc-d57694d382bc49d5b53ff470ce001219) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {1, "", "", "", ""}
};

CarStruct audiCars[] = {
    {100, "Audi R8 Green Hell Edition (2021)", "Load R8 GH", "r8_gh", "This work is based on \"2021 Audi R8 Green Hell Edition\" (https://sketchfab.com/3d-models/2021-audi-r8-green-hell-edition-8ab3e0f5f18b46508fd9caefbf0f9b33) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {10, "Audi R8 LMS (2015)", "Load R8 LMS", "r8_lms", "This work is based on \"2015 Audi R8 LMS\" (https://sketchfab.com/3d-models/2015-audi-r8-lms-e36735f57d014dc7b3cddba772f187ea) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {100, "Audi RS3 Sportback (2018)", "Load RS3", "rs3", "This work is based on \"2018 Audi RS3 Sportback\" (https://sketchfab.com/3d-models/2018-audi-rs3-sportback-20fdc17a5b2f4afab096337b5822c170) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {1, "", "", "", ""}
};

#define VW_CARS 4
#define AUDI_CARS 3