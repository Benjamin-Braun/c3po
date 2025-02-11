#include "main.h"

struct CarStruct {
    int scale;
    string title;
    string folder;
    string credits;
};

CarStruct vwCars[] = {
    {100, "Volkswagen Golf GTI (1992)", "1992_gti", "This work is based on \"1992 Volkswagen Golf GTI Mk2\" (https://sketchfab.com/3d-models/1992-volkswagen-golf-gti-mk2-1fb8f26b105445fbaa98ca2577f7067e) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {100, "Volkswagen Golf GTI (2014)", "2014_gti", "This work is based on \"2014 Volkswagen Golf GTI Mk7\" (https://sketchfab.com/3d-models/2014-volkswagen-golf-gti-mk7-93f2b79c56c14b269fbe914205c4712e) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {1, "Volkswagen Jetta (2019)", "jetta", "This work is based on \"2019 Volkswagen Jetta\" (https://sketchfab.com/3d-models/2019-volkswagen-jetta-c9031d4501f74639a2552539fd2dba36) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {100, "Volkswagen Polo R WRC (2015)", "polo_wrc", "This work is based on \"2015 Volkswagen Polo R WRC\" (https://sketchfab.com/3d-models/2015-volkswagen-polo-r-wrc-d57694d382bc49d5b53ff470ce001219) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {100, "Volkswagen Amarok V6 (2017)", "amarok", "This work is based on \"2017 Volkswagen Amarok V6\" (https://sketchfab.com/3d-models/2017-volkswagen-amarok-v6-3272be01e2f946c4bda1c1b5ed73d3a4) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {100, "Volkswagen ID.6 X (2021)", "id6", "This work is based on \"2021 Volkswagen ID.6 X\" (https://sketchfab.com/3d-models/2021-volkswagen-id6-x-a3dd4f3e9ecf4f858aa19ac7534676d3) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {1, "Volkswagen Lamando Black Pack (2020)", "lamando", "This work is based on \"2020 Volkswagen Lamando Black Pack\" (https://sketchfab.com/3d-models/2020-volkswagen-lamando-black-pack-9044b55d49ef4a4b9aa5c7077a12478f) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {1, "Volkswagen Passat PHEV (2022)", "passat", "This work is based on \"2022 Volkswagen Passat PHEV\" (https://sketchfab.com/3d-models/2022-volkswagen-passat-phev-0e668a2cc10647b1a6e47e06384aa26a) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {1, "Volkswagen Polo Plus (2021)", "polo", "This work is based on \"2021 Volkswagen Polo Plus\" (https://sketchfab.com/3d-models/2021-volkswagen-polo-plus-7e0130019e1b4feea72f2daa2c0cfd78) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {100, "Volkswagen Teramont 530 V6 4Motion (2022)", "teramont", "This work is based on \"2022 Volkswagen Teramont 530 V6 4Motion\" (https://sketchfab.com/3d-models/2022-volkswagen-teramont-530-v6-4motion-ed2878a43724426b9c1f8d670f0e6073) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {100, "Volkswagen Tiguan L - Allspace (2022)", "tiguan", "This work is based on \"2022 Volkswagen Tiguan L - Allspace\" (https://sketchfab.com/3d-models/2022-volkswagen-tiguan-l-allspace-c8780d08e8dc4050a1287fa99c31824c) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {1, "", "", ""}
};

CarStruct audiCars[] = {
    {100, "Audi R8 Green Hell Edition (2021)", "r8_gh", "This work is based on \"2021 Audi R8 Green Hell Edition\" (https://sketchfab.com/3d-models/2021-audi-r8-green-hell-edition-8ab3e0f5f18b46508fd9caefbf0f9b33) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {10, "Audi R8 LMS (2015)", "r8_lms", "This work is based on \"2015 Audi R8 LMS\" (https://sketchfab.com/3d-models/2015-audi-r8-lms-e36735f57d014dc7b3cddba772f187ea) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {100, "Audi RS3 Sportback (2018)", "rs3", "This work is based on \"2018 Audi RS3 Sportback\" (https://sketchfab.com/3d-models/2018-audi-rs3-sportback-20fdc17a5b2f4afab096337b5822c170) by Ddiaz Design (https://sketchfab.com/ddiaz-design) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/)"},
    {1, "", "", ""}
};

CarStruct ferrariCars[] = {
    {1, "", "", ""}
};

CarStruct jaguarCars[] = {
    {1, "", "", ""}
};

CarStruct lamboCars[] = {
    {1, "", "", ""}
};

CarStruct porscheCars[] = {
    {1, "", "", ""}
};

#define VW_CARS 11
#define AUDI_CARS 3
#define FERRARI_CARS 1
#define JAGUAR_CARS 1
#define LAMBO_CARS 1
#define PORSCHE_CARS 1