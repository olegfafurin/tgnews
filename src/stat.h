//
// Created by imd on 11/26/2019.
//

#ifndef TELEGRAM_ARTICLE_STAT_H
#define TELEGRAM_ARTICLE_STAT_H

const std::map<std::string, int> BISTAT_ENG({{"aa", 3}, {"ab", 1063}, {"ac", 2106}, {"ad", 3529}, {"ae", 3}, {"af", 467}, {"ag", 1046}, {"ah", 116}, {"ai", 2914}, {"aj", 12}, {"ak", 924}, {"al", 3968}, {"am", 1737}, {"an", 13468}, {"ao", 12}, {"ap", 943}, {"aq", 4}, {"ar", 5988}, {"as", 7023}, {"at", 7443}, {"au", 689}, {"av", 1823}, {"aw", 672}, {"ax", 169}, {"ay", 1627}, {"az", 110}, {"a ", 4994}, {"ba", 559}, {"bb", 83}, {"bd", 16}, {"be", 4005}, {"bh", 9}, {"bi", 309}, {"bj", 77}, {"bl", 1390}, {"bm", 19}, {"bn", 4}, {"bo", 993}, {"br", 972}, {"bs", 253}, {"bt", 120}, {"bu", 1574}, {"bv", 7}, {"bw", 1}, {"by", 704}, {"b ", 82}, {"ca", 2094}, {"cb", 1}, {"cc", 371}, {"ce", 3473}, {"ch", 3750}, {"ci", 755}, {"ck", 936}, {"cl", 858}, {"co", 3525}, {"cq", 41}, {"cr", 621}, {"cs", 22}, {"ct", 1317}, {"cu", 663}, {"cx", 1}, {"cy", 106}, {"c ", 203}, {"da", 938}, {"db", 4}, {"dc", 3}, {"dd", 279}, {"de", 4002}, {"df", 24}, {"dg", 160}, {"dh", 21}, {"di", 2270}, {"dj", 9}, {"dk", 18}, {"dl", 345}, {"dm", 58}, {"dn", 97}, {"do", 1825}, {"dr", 783}, {"ds", 734}, {"dt", 11}, {"du", 357}, {"dv", 98}, {"dw", 46}, {"dy", 322}, {"d ", 24929}, {"ea", 5239}, {"eb", 111}, {"ec", 1772}, {"ed", 9993}, {"ee", 3048}, {"ef", 950}, {"eg", 402}, {"eh", 250}, {"ei", 968}, {"ej", 39}, {"ek", 167}, {"el", 3685}, {"em", 1942}, {"en", 8218}, {"eo", 196}, {"ep", 971}, {"eq", 186}, {"er", 13278}, {"es", 6400}, {"et", 2581}, {"eu", 52}, {"ev", 1467}, {"ew", 702}, {"ex", 898}, {"ey", 1218}, {"ez", 28}, {"e ", 35775}, {"fa", 1470}, {"fe", 1670}, {"ff", 683}, {"fi", 1389}, {"fl", 442}, {"fn", 2}, {"fo", 2812}, {"fr", 1279}, {"fs", 11}, {"ft", 678}, {"fu", 644}, {"fy", 37}, {"f ", 5777}, {"ga", 1006}, {"gd", 4}, {"ge", 2082}, {"gg", 146}, {"gh", 2236}, {"gi", 754}, {"gl", 592}, {"gm", 50}, {"gn", 202}, {"go", 1113}, {"gr", 948}, {"gs", 338}, {"gt", 60}, {"gu", 360}, {"gy", 66}, {"g ", 5149}, {"ha", 8166}, {"hb", 21}, {"hc", 1}, {"hd", 34}, {"he", 20474}, {"hf", 33}, {"hh", 2}, {"hi", 5495}, {"hl", 60}, {"hm", 58}, {"hn", 214}, {"ho", 3480}, {"hq", 4}, {"hr", 468}, {"hs", 72}, {"ht", 1620}, {"hu", 572}, {"hw", 14}, {"hy", 222}, {"h ", 4871}, {"ia", 701}, {"ib", 337}, {"ic", 1966}, {"id", 2235}, {"ie", 1978}, {"if", 1199}, {"ig", 1507}, {"ih", 5}, {"ii", 3}, {"ik", 563}, {"il", 2941}, {"im", 1983}, {"in", 13355}, {"io", 2201}, {"ip", 328}, {"iq", 28}, {"ir", 2581}, {"is", 6252}, {"it", 7171}, {"iu", 36}, {"iv", 1208}, {"iw", 1}, {"ix", 85}, {"iz", 80}, {"i ", 7298}, {"ja", 415}, {"je", 159}, {"ji", 1}, {"jo", 345}, {"ju", 301}, {"j ", 9}, {"ka", 14}, {"kb", 4}, {"kc", 4}, {"ke", 2249}, {"kf", 49}, {"kg", 3}, {"kh", 5}, {"ki", 653}, {"kl", 133}, {"kn", 586}, {"ko", 6}, {"kr", 1}, {"ks", 222}, {"kw", 10}, {"ky", 52}, {"k ", 2047}, {"la", 2564}, {"lb", 12}, {"lc", 80}, {"ld", 2614}, {"le", 5631}, {"lf", 622}, {"lg", 25}, {"lh", 1}, {"li", 3635}, {"lk", 252}, {"ll", 4645}, {"lm", 197}, {"ln", 29}, {"lo", 2873}, {"lp", 86}, {"lr", 86}, {"ls", 462}, {"lt", 546}, {"lu", 455}, {"lv", 129}, {"lw", 91}, {"ly", 2623}, {"l ", 4845}, {"ma", 2531}, {"mb", 450}, {"mc", 1}, {"md", 2}, {"me", 6199}, {"mf", 49}, {"mi", 1973}, {"ml", 45}, {"mm", 301}, {"mn", 76}, {"mo", 1907}, {"mp", 914}, {"mr", 802}, {"ms", 339}, {"mt", 13}, {"mu", 779}, {"mw", 1}, {"my", 2501}, {"m ", 3403}, {"na", 1134}, {"nb", 23}, {"nc", 2083}, {"nd", 10214}, {"ne", 5126}, {"nf", 386}, {"ng", 6499}, {"nh", 28}, {"ni", 1482}, {"nj", 76}, {"nk", 487}, {"nl", 484}, {"nm", 33}, {"nn", 557}, {"no", 4606}, {"np", 15}, {"nq", 113}, {"nr", 36}, {"ns", 1758}, {"nt", 4719}, {"nu", 415}, {"nv", 195}, {"nw", 42}, {"nx", 23}, {"ny", 523}, {"nz", 13}, {"n ", 13243}, {"oa", 379}, {"ob", 413}, {"oc", 960}, {"od", 997}, {"oe", 140}, {"of", 4856}, {"og", 170}, {"oh", 322}, {"oi", 607}, {"oj", 8}, {"ok", 978}, {"ol", 1617}, {"om", 3401}, {"on", 7906}, {"oo", 3170}, {"op", 794}, {"oq", 15}, {"or", 6210}, {"os", 1480}, {"ot", 3203}, {"ou", 9975}, {"ov", 1043}, {"ow", 3201}, {"ox", 32}, {"oy", 154}, {"oz", 22}, {"o ", 8576}, {"pa", 1635}, {"pb", 8}, {"pd", 3}, {"pe", 2397}, {"pg", 1}, {"ph", 182}, {"pi", 736}, {"pl", 1214}, {"pm", 4}, {"po", 1286}, {"pp", 799}, {"pr", 1609}, {"ps", 339}, {"pt", 383}, {"pu", 485}, {"pw", 5}, {"py", 81}, {"p ", 945}, {"qu", 944}, {"q ", 3}, {"ra", 2985}, {"rb", 130}, {"rc", 488}, {"rd", 1305}, {"re", 11449}, {"rf", 276}, {"rg", 446}, {"rh", 131}, {"ri", 2999}, {"rj", 2}, {"rk", 342}, {"rl", 529}, {"rm", 655}, {"rn", 1222}, {"ro", 4191}, {"rp", 194}, {"rr", 828}, {"rs", 2327}, {"rt", 1803}, {"ru", 671}, {"rv", 352}, {"rw", 97}, {"ry", 1447}, {"r ", 12543}, {"sa", 1942}, {"sb", 39}, {"sc", 802}, {"sd", 23}, {"se", 5811}, {"sf", 58}, {"sg", 27}, {"sh", 3817}, {"si", 2784}, {"sj", 2}, {"sk", 415}, {"sl", 329}, {"sm", 280}, {"sn", 113}, {"so", 2723}, {"sp", 1071}, {"sq", 31}, {"sr", 11}, {"ss", 2792}, {"st", 6710}, {"su", 1691}, {"sw", 342}, {"sy", 147}, {"s ", 18184}, {"ta", 2263}, {"tb", 2}, {"tc", 313}, {"td", 2}, {"te", 6358}, {"tf", 52}, {"tg", 1}, {"th", 18822}, {"ti", 4193}, {"tl", 1080}, {"tm", 92}, {"tn", 83}, {"to", 7193}, {"tr", 1929}, {"ts", 1101}, {"tt", 1371}, {"tu", 1258}, {"tw", 394}, {"ty", 836}, {"tz", 4}, {"t ", 19784}, {"ua", 457}, {"ub", 340}, {"uc", 779}, {"ud", 445}, {"ue", 674}, {"uf", 140}, {"ug", 1221}, {"ui", 719}, {"uk", 3}, {"ul", 2553}, {"um", 497}, {"un", 2119}, {"uo", 32}, {"up", 898}, {"ur", 3966}, {"us", 2594}, {"ut", 2993}, {"uu", 3}, {"uv", 8}, {"ux", 10}, {"uy", 9}, {"uz", 23}, {"u ", 3023}, {"va", 489}, {"ve", 5754}, {"vi", 910}, {"vo", 400}, {"vr", 5}, {"vu", 16}, {"vy", 34}, {"v ", 5}, {"wa", 4071}, {"wb", 2}, {"wd", 14}, {"we", 2649}, {"wf", 19}, {"wg", 2}, {"wh", 3296}, {"wi", 3246}, {"wk", 2}, {"wl", 91}, {"wm", 1}, {"wn", 728}, {"wo", 1753}, {"wr", 176}, {"ws", 140}, {"wt", 16}, {"ww", 2}, {"wy", 21}, {"w ", 2484}, {"xa", 81}, {"xc", 197}, {"xe", 84}, {"xg", 1}, {"xh", 15}, {"xi", 112}, {"xo", 12}, {"xp", 329}, {"xq", 10}, {"xt", 139}, {"xu", 11}, {"xw", 1}, {"xy", 4}, {"x ", 221}, {"ya", 53}, {"yb", 23}, {"yc", 5}, {"yd", 12}, {"ye", 1139}, {"yf", 2}, {"yg", 1}, {"yh", 3}, {"yi", 179}, {"yl", 52}, {"ym", 98}, {"yn", 30}, {"yo", 3963}, {"yp", 18}, {"yr", 124}, {"ys", 505}, {"yt", 86}, {"yw", 20}, {"y ", 11008}, {"za", 41}, {"zb", 1}, {"ze", 151}, {"zi", 23}, {"zj", 1}, {"zl", 30}, {"zo", 15}, {"zu", 7}, {"zy", 8}, {"zz", 36}, {"z ", 16}, {" a", 21628}, {" b", 8111}, {" c", 6820}, {" d", 5747}, {" e", 3825}, {" f", 7030}, {" g", 3447}, {" h", 12874}, {" i", 16934}, {" j", 1004}, {" k", 951}, {" l", 5274}, {" m", 10881}, {" n", 5305}, {" o", 9997}, {" p", 4755}, {" q", 515}, {" r", 4708}, {" s", 14980}, {" t", 24142}, {" u", 1548}, {" v", 1282}, {" w", 13072}, {" y", 4579}, {" z", 13}, {"__", 1}});
//const std::map<std::string, int> BISTAT_RUS({ {"аа", 5},{"аб", 424},{"ав", 2174},{"аг", 605},{"ад", 1341},{"ае", 538},{"аж", 759},{"аз", 2547},{"аи", 77},{"ай", 479},{"ак", 2729},{"ал", 5654},{"ам", 1698},{"ан", 3253},{"ао", 3},{"ап", 458},{"ар", 1698},{"ас", 2364},{"ат", 2946},{"ау", 86},{"аф", 322},{"ах", 613},{"ац", 55},{"ач", 468},{"аш", 609},{"ащ", 151},{"аэ", 1},{"аю", 489},{"ая", 1757},{"а ", 10898},{"ба", 727},{"бб", 16},{"бв", 24},{"бг", 11},{"бд", 9},{"бе", 1254},{"бж", 3},{"бз", 1},{"би", 468},{"бк", 158},{"бл", 477},{"бм", 39},{"бн", 160},{"бо", 1379},{"бр", 747},{"бс", 44},{"бт", 5},{"бу", 726},{"бх", 29},{"бц", 4},{"бч", 16},{"бш", 3},{"бщ", 104},{"бъ", 46},{"бы", 2269},{"бь", 30},{"бэ", 1},{"бю", 4},{"бя", 294},{"б ", 199},{"ва", 3668},{"вб", 6},{"вв", 14},{"вг", 14},{"вд", 172},{"ве", 2659},{"вз", 327},{"ви", 2086},{"вк", 80},{"вл", 591},{"вм", 88},{"вн", 854},{"во", 4446},{"вп", 196},{"вр", 301},{"вс", 1894},{"вт", 125},{"ву", 506},{"вх", 25},{"вц", 8},{"вч", 19},{"вш", 795},{"вщ", 4},{"въ", 10},{"вы", 1681},{"вь", 102},{"вэ", 1},{"вя", 79},{"в ", 3896},{"га", 642},{"гв", 48},{"гд", 545},{"ге", 354},{"ги", 516},{"гк", 67},{"гл", 1037},{"гм", 7},{"гн", 182},{"го", 5717},{"гр", 861},{"гс", 23},{"гт", 2},{"гу", 494},{"гч", 14},{"гш", 4},{"г ", 613},{"да", 2559},{"дб", 22},{"дв", 586},{"дг", 6},{"дд", 13},{"де", 2708},{"дж", 8},{"дз", 3},{"ди", 1734},{"дк", 131},{"дл", 388},{"дм", 56},{"дн", 1041},{"до", 2221},{"дп", 61},{"др", 1297},{"дс", 169},{"дт", 186},{"ду", 1015},{"дф", 8},{"дх", 33},{"дц", 103},{"дч", 14},{"дш", 66},{"дъ", 182},{"ды", 419},{"дь", 307},{"дэ", 1},{"дю", 9},{"дя", 230},{"д ", 699},{"еа", 6},{"еб", 664},{"ев", 835},{"ег", 2127},{"ед", 1535},{"ее", 920},{"еж", 591},{"ез", 685},{"еи", 103},{"ей", 1455},{"ек", 619},{"ел", 3764},{"ем", 2374},{"ен", 4255},{"ео", 155},{"еп", 596},{"ер", 4307},{"ес", 2179},{"ет", 2216},{"еу", 42},{"еф", 8},{"ех", 659},{"ец", 172},{"еч", 569},{"еш", 456},{"ещ", 410},{"ею", 217},{"ея", 236},{"е ", 10411},{"жа", 851},{"жб", 32},{"жг", 15},{"жд", 395},{"же", 2363},{"жж", 8},{"жи", 696},{"жк", 54},{"жл", 1},{"жм", 7},{"жн", 647},{"жо", 22},{"жс", 13},{"жу", 119},{"жч", 30},{"жь", 22},{"жэ", 1},{"жю", 13},{"ж ", 131},{"за", 3464},{"зб", 91},{"зв", 478},{"зг", 276},{"зд", 422},{"зе", 131},{"зж", 108},{"зз", 4},{"зи", 198},{"зк", 104},{"зл", 112},{"зм", 158},{"зн", 965},{"зо", 440},{"зр", 93},{"зс", 94},{"зт", 6},{"зу", 164},{"зц", 2},{"зч", 8},{"зш", 8},{"зъ", 10},{"зы", 339},{"зь", 693},{"зю", 72},{"зя", 325},{"з ", 781},{"иа", 45},{"иб", 308},{"ив", 1655},{"иг", 303},{"ид", 1095},{"ие", 1486},{"иж", 245},{"из", 1048},{"ии", 397},{"ий", 905},{"ик", 1046},{"ил", 3117},{"им", 1793},{"ин", 2024},{"ио", 173},{"ип", 137},{"ир", 419},{"ис", 1779},{"ит", 2081},{"иу", 1},{"иф", 10},{"их", 1064},{"иц", 899},{"ич", 738},{"иш", 225},{"ищ", 67},{"ию", 185},{"ия", 998},{"и ", 11348},{"йб", 3},{"йд", 114},{"йе", 7},{"йк", 25},{"йл", 144},{"йм", 26},{"йн", 211},{"йо", 8},{"йр", 36},{"йс", 415},{"йт", 166},{"йц", 23},{"йч", 34},{"йш", 51},{"йщ", 1},{"й ", 4896},{"ка", 5091},{"кв", 107},{"кг", 2},{"кд", 12},{"ке", 302},{"кж", 7},{"кз", 4},{"ки", 1590},{"кк", 6},{"кл", 228},{"кн", 1441},{"ко", 5222},{"кр", 1087},{"кс", 43},{"кт", 240},{"ку", 967},{"кх", 2},{"кц", 7},{"кч", 2},{"кш", 4},{"кю", 10},{"к ", 3138},{"ла", 4068},{"лб", 15},{"лв", 6},{"лг", 94},{"лд", 210},{"ле", 2325},{"лж", 212},{"лз", 4},{"ли", 4021},{"лк", 499},{"лл", 73},{"лм", 3},{"лн", 160},{"ло", 3976},{"лп", 66},{"лс", 860},{"лт", 27},{"лу", 747},{"лф", 5},{"лч", 133},{"лш", 1},{"лщ", 1},{"лы", 772},{"ль", 2186},{"лэ", 1},{"лю", 515},{"ля", 1093},{"л ", 5041},{"ма", 1745},{"мб", 2},{"мг", 38},{"ме", 1708},{"мз", 2},{"ми", 2183},{"мк", 43},{"мл", 48},{"мм", 10},{"мн", 709},{"мо", 2217},{"мп", 139},{"мр", 27},{"мс", 84},{"мт", 10},{"му", 1391},{"мф", 1},{"мц", 22},{"мч", 17},{"мш", 4},{"мщ", 1},{"мы", 394},{"мь", 15},{"мэ", 1},{"мю", 39},{"мя", 276},{"м ", 4660},{"на", 6499},{"нб", 7},{"нв", 6},{"нг", 105},{"нд", 718},{"не", 5502},{"нж", 14},{"нз", 11},{"ни", 4178},{"нк", 139},{"нл", 1},{"нм", 1},{"нн", 1821},{"но", 5610},{"нп", 6},{"нр", 25},{"нс", 254},{"нт", 378},{"ну", 1683},{"нф", 6},{"нц", 361},{"нч", 120},{"нш", 22},{"нщ", 91},{"ны", 1935},{"нь", 634},{"нэ", 2},{"ню", 95},{"ня", 2122},{"н ", 2857},{"оа", 1},{"об", 1928},{"ов", 5092},{"ог", 2937},{"од", 2829},{"ое", 1330},{"ож", 1005},{"оз", 552},{"ои", 494},{"ой", 2282},{"ок", 1060},{"ол", 4292},{"ом", 3073},{"он", 4196},{"оо", 103},{"оп", 686},{"ор", 3912},{"ос", 4420},{"от", 4090},{"оу", 31},{"оф", 280},{"ох", 344},{"оц", 54},{"оч", 833},{"ош", 815},{"ощ", 79},{"оэ", 14},{"ою", 467},{"оя", 386},{"о ", 13637},{"па", 733},{"пг", 9},{"пе", 1543},{"пи", 475},{"пк", 39},{"пл", 452},{"пн", 33},{"по", 5433},{"пп", 51},{"пр", 3765},{"пс", 2},{"пт", 31},{"пу", 436},{"пц", 1},{"пч", 5},{"пш", 8},{"пы", 125},{"пь", 375},{"пэ", 2},{"пя", 227},{"п ", 21},{"ра", 5294},{"рб", 77},{"рв", 159},{"рг", 175},{"рд", 254},{"ре", 3776},{"рж", 232},{"рз", 21},{"ри", 3304},{"рк", 162},{"рл", 38},{"рм", 148},{"рн", 409},{"ро", 4351},{"рп", 27},{"рр", 27},{"рс", 151},{"рт", 406},{"ру", 1940},{"рф", 13},{"рх", 84},{"рц", 61},{"рч", 51},{"рш", 143},{"рщ", 41},{"ры", 903},{"рь", 512},{"рэ", 2},{"рю", 129},{"ря", 673},{"р ", 821},{"са", 895},{"сб", 27},{"св", 1090},{"сг", 5},{"сд", 190},{"се", 2123},{"сж", 14},{"сз", 32},{"си", 1049},{"ск", 3267},{"сл", 1467},{"см", 619},{"сн", 756},{"со", 1556},{"сп", 1072},{"ср", 165},{"сс", 475},{"ст", 6618},{"су", 459},{"сф", 11},{"сх", 116},{"сц", 13},{"сч", 202},{"сш", 32},{"съ", 8},{"сы", 252},{"сь", 2104},{"сэ", 1},{"сю", 82},{"ся", 1932},{"с ", 1937},{"та", 3415},{"тб", 18},{"тв", 1340},{"тг", 6},{"тд", 82},{"те", 2868},{"тж", 1},{"тз", 4},{"ти", 2131},{"тк", 217},{"тл", 172},{"тм", 30},{"тн", 557},{"то", 8443},{"тп", 38},{"тр", 1783},{"тс", 512},{"тт", 66},{"ту", 1116},{"тф", 9},{"тх", 14},{"тц", 76},{"тч", 103},{"тщ", 12},{"тъ", 25},{"ты", 983},{"ть", 3094},{"тэ", 6},{"тю", 34},{"тя", 309},{"т ", 2887},{"уа", 12},{"уб", 323},{"ув", 533},{"уг", 782},{"уд", 1215},{"уе", 90},{"уж", 803},{"уз", 550},{"уи", 11},{"уй", 56},{"ук", 623},{"ул", 953},{"ум", 627},{"ун", 190},{"уо", 8},{"уп", 348},{"ур", 360},{"ус", 885},{"ут", 882},{"уу", 1},{"уф", 4},{"ух", 227},{"уц", 1},{"уч", 439},{"уш", 480},{"ущ", 122},{"уэ", 14},{"ую", 634},{"уя", 43},{"у ", 4153},{"фа", 114},{"фе", 87},{"фи", 401},{"фк", 7},{"фл", 58},{"фм", 3},{"фо", 37},{"фр", 305},{"фс", 4},{"фт", 4},{"фу", 45},{"фф", 3},{"фы", 12},{"фь", 1},{"фэ", 1},{"ф ", 117},{"ха", 619},{"хв", 82},{"хе", 24},{"хи", 98},{"хл", 39},{"хм", 35},{"хн", 95},{"хо", 1428},{"хп", 1},{"хр", 47},{"хс", 23},{"хт", 12},{"ху", 77},{"хъ", 2},{"х ", 1989},{"ца", 359},{"цв", 12},{"цг", 17},{"це", 680},{"ци", 143},{"цк", 110},{"цл", 3},{"цн", 16},{"цо", 262},{"цу", 312},{"цы", 74},{"ц ", 175},{"ча", 1351},{"че", 1871},{"чи", 742},{"чк", 143},{"чл", 23},{"чн", 291},{"чо", 59},{"чр", 13},{"чт", 2171},{"чу", 364},{"чш", 44},{"чь", 123},{"чэ", 1},{"ч ", 101},{"ша", 872},{"шв", 10},{"ше", 1371},{"ши", 1218},{"шк", 257},{"шл", 287},{"шм", 12},{"шн", 210},{"шо", 204},{"шп", 34},{"шр", 2},{"шс", 1},{"шт", 101},{"шу", 183},{"шь", 204},{"ш ", 70},{"ща", 259},{"ще", 753},{"щи", 412},{"щн", 17},{"щр", 1},{"щу", 42},{"щь", 12},{"щэ", 1},{"щ ", 7},{"ъе", 142},{"ъю", 109},{"ъя", 32},{"ъ ", 1},{"ыб", 318},{"ыв", 683},{"ыг", 69},{"ыд", 51},{"ые", 570},{"ыж", 18},{"ыз", 29},{"ыи", 8},{"ый", 947},{"ык", 116},{"ыл", 1391},{"ым", 924},{"ын", 219},{"ыо", 1},{"ып", 79},{"ыр", 222},{"ыс", 495},{"ыт", 336},{"ыу", 3},{"ых", 545},{"ыц", 1},{"ыч", 82},{"ыш", 329},{"ыщ", 1},{"ы ", 2724},{"ьб", 66},{"ьв", 3},{"ьг", 26},{"ьд", 22},{"ье", 588},{"ьз", 83},{"ьи", 46},{"ьк", 695},{"ьм", 217},{"ьн", 635},{"ьо", 27},{"ьс", 551},{"ьт", 62},{"ьф", 4},{"ьц", 55},{"ьч", 26},{"ьш", 257},{"ьщ", 5},{"ью", 227},{"ья", 241},{"ь ", 6580},{"эг", 6},{"эд", 2},{"эз", 2},{"эй", 7},{"эк", 33},{"эл", 50},{"эм", 6},{"эн", 30},{"эп", 6},{"эр", 32},{"эс", 46},{"эт", 1372},{"эх", 3},{"эц", 1},{"эш", 1},{"э ", 13},{"юб", 188},{"юг", 1},{"юд", 221},{"юж", 4},{"юз", 17},{"юк", 2},{"юл", 25},{"юм", 16},{"юн", 52},{"юр", 41},{"юс", 89},{"ют", 259},{"юх", 4},{"юц", 29},{"юч", 37},{"юш", 43},{"ющ", 276},{"юю", 23},{"ю ", 2134},{"яб", 21},{"яв", 167},{"яг", 190},{"яд", 453},{"яе", 61},{"яж", 322},{"яз", 971},{"яи", 7},{"яй", 12},{"як", 48},{"ял", 561},{"ям", 208},{"ян", 384},{"яп", 9},{"яр", 25},{"яс", 554},{"ят", 880},{"яф", 1},{"ях", 89},{"яц", 21},{"яч", 76},{"яш", 2},{"ящ", 91},{"яю", 56},{"яя", 128},{"я ", 7035},{" а", 1914},{" б", 4691},{" в", 9542},{" г", 3306},{" д", 4375},{" е", 2430},{" ж", 1066},{" з", 2652},{" и", 6805},{" й", 17},{" к", 7033},{" л", 1665},{" м", 3608},{" н", 9388},{" о", 7722},{" п", 9759},{" р", 2792},{" с", 10150},{" т", 4673},{" у", 2419},{" ф", 514},{" х", 720},{" ц", 194},{" ч", 3261},{" ш", 635},{" щ", 47},{" ъ", 1},{" ы", 2},{" ь", 1},{" э", 1559},{" ю", 52},{" я", 991}, {"__", 1}});
const std::map<std::pair<int, int>, int> BISTAT_RUS({ {{224,224}, 5},{{224,225}, 424},{{224,226}, 2174},{{224,227}, 605},{{224,228}, 1341},{{224,229}, 538},{{224,230}, 759},{{224,231}, 2547},{{224,232}, 77},{{224,233}, 479},{{224,234}, 2729},{{224,235}, 5654},{{224,236}, 1698},{{224,237}, 3253},{{224,238}, 3},{{224,239}, 458},{{224,240}, 1698},{{224,241}, 2364},{{224,242}, 2946},{{224,243}, 86},{{224,244}, 322},{{224,245}, 613},{{224,246}, 55},{{224,247}, 468},{{224,248}, 609},{{224,249}, 151},{{224,253}, 1},{{224,254}, 489},{{224,255}, 1757},{{224,32}, 10898},{{225,224}, 727},{{225,225}, 16},{{225,226}, 24},{{225,227}, 11},{{225,228}, 9},{{225,229}, 1254},{{225,230}, 3},{{225,231}, 1},{{225,232}, 468},{{225,234}, 158},{{225,235}, 477},{{225,236}, 39},{{225,237}, 160},{{225,238}, 1379},{{225,240}, 747},{{225,241}, 44},{{225,242}, 5},{{225,243}, 726},{{225,245}, 29},{{225,246}, 4},{{225,247}, 16},{{225,248}, 3},{{225,249}, 104},{{225,250}, 46},{{225,251}, 2269},{{225,252}, 30},{{225,253}, 1},{{225,254}, 4},{{225,255}, 294},{{225,32}, 199},{{226,224}, 3668},{{226,225}, 6},{{226,226}, 14},{{226,227}, 14},{{226,228}, 172},{{226,229}, 2659},{{226,231}, 327},{{226,232}, 2086},{{226,234}, 80},{{226,235}, 591},{{226,236}, 88},{{226,237}, 854},{{226,238}, 4446},{{226,239}, 196},{{226,240}, 301},{{226,241}, 1894},{{226,242}, 125},{{226,243}, 506},{{226,245}, 25},{{226,246}, 8},{{226,247}, 19},{{226,248}, 795},{{226,249}, 4},{{226,250}, 10},{{226,251}, 1681},{{226,252}, 102},{{226,253}, 1},{{226,255}, 79},{{226,32}, 3896},{{227,224}, 642},{{227,226}, 48},{{227,228}, 545},{{227,229}, 354},{{227,232}, 516},{{227,234}, 67},{{227,235}, 1037},{{227,236}, 7},{{227,237}, 182},{{227,238}, 5717},{{227,240}, 861},{{227,241}, 23},{{227,242}, 2},{{227,243}, 494},{{227,247}, 14},{{227,248}, 4},{{227,32}, 613},{{228,224}, 2559},{{228,225}, 22},{{228,226}, 586},{{228,227}, 6},{{228,228}, 13},{{228,229}, 2708},{{228,230}, 8},{{228,231}, 3},{{228,232}, 1734},{{228,234}, 131},{{228,235}, 388},{{228,236}, 56},{{228,237}, 1041},{{228,238}, 2221},{{228,239}, 61},{{228,240}, 1297},{{228,241}, 169},{{228,242}, 186},{{228,243}, 1015},{{228,244}, 8},{{228,245}, 33},{{228,246}, 103},{{228,247}, 14},{{228,248}, 66},{{228,250}, 182},{{228,251}, 419},{{228,252}, 307},{{228,253}, 1},{{228,254}, 9},{{228,255}, 230},{{228,32}, 699},{{229,224}, 6},{{229,225}, 664},{{229,226}, 835},{{229,227}, 2127},{{229,228}, 1535},{{229,229}, 920},{{229,230}, 591},{{229,231}, 685},{{229,232}, 103},{{229,233}, 1455},{{229,234}, 619},{{229,235}, 3764},{{229,236}, 2374},{{229,237}, 4255},{{229,238}, 155},{{229,239}, 596},{{229,240}, 4307},{{229,241}, 2179},{{229,242}, 2216},{{229,243}, 42},{{229,244}, 8},{{229,245}, 659},{{229,246}, 172},{{229,247}, 569},{{229,248}, 456},{{229,249}, 410},{{229,254}, 217},{{229,255}, 236},{{229,32}, 10411},{{230,224}, 851},{{230,225}, 32},{{230,227}, 15},{{230,228}, 395},{{230,229}, 2363},{{230,230}, 8},{{230,232}, 696},{{230,234}, 54},{{230,235}, 1},{{230,236}, 7},{{230,237}, 647},{{230,238}, 22},{{230,241}, 13},{{230,243}, 119},{{230,247}, 30},{{230,252}, 22},{{230,253}, 1},{{230,254}, 13},{{230,32}, 131},{{231,224}, 3464},{{231,225}, 91},{{231,226}, 478},{{231,227}, 276},{{231,228}, 422},{{231,229}, 131},{{231,230}, 108},{{231,231}, 4},{{231,232}, 198},{{231,234}, 104},{{231,235}, 112},{{231,236}, 158},{{231,237}, 965},{{231,238}, 440},{{231,240}, 93},{{231,241}, 94},{{231,242}, 6},{{231,243}, 164},{{231,246}, 2},{{231,247}, 8},{{231,248}, 8},{{231,250}, 10},{{231,251}, 339},{{231,252}, 693},{{231,254}, 72},{{231,255}, 325},{{231,32}, 781},{{232,224}, 45},{{232,225}, 308},{{232,226}, 1655},{{232,227}, 303},{{232,228}, 1095},{{232,229}, 1486},{{232,230}, 245},{{232,231}, 1048},{{232,232}, 397},{{232,233}, 905},{{232,234}, 1046},{{232,235}, 3117},{{232,236}, 1793},{{232,237}, 2024},{{232,238}, 173},{{232,239}, 137},{{232,240}, 419},{{232,241}, 1779},{{232,242}, 2081},{{232,243}, 1},{{232,244}, 10},{{232,245}, 1064},{{232,246}, 899},{{232,247}, 738},{{232,248}, 225},{{232,249}, 67},{{232,254}, 185},{{232,255}, 998},{{232,32}, 11348},{{233,225}, 3},{{233,228}, 114},{{233,229}, 7},{{233,234}, 25},{{233,235}, 144},{{233,236}, 26},{{233,237}, 211},{{233,238}, 8},{{233,240}, 36},{{233,241}, 415},{{233,242}, 166},{{233,246}, 23},{{233,247}, 34},{{233,248}, 51},{{233,249}, 1},{{233,32}, 4896},{{234,224}, 5091},{{234,226}, 107},{{234,227}, 2},{{234,228}, 12},{{234,229}, 302},{{234,230}, 7},{{234,231}, 4},{{234,232}, 1590},{{234,234}, 6},{{234,235}, 228},{{234,237}, 1441},{{234,238}, 5222},{{234,240}, 1087},{{234,241}, 43},{{234,242}, 240},{{234,243}, 967},{{234,245}, 2},{{234,246}, 7},{{234,247}, 2},{{234,248}, 4},{{234,254}, 10},{{234,32}, 3138},{{235,224}, 4068},{{235,225}, 15},{{235,226}, 6},{{235,227}, 94},{{235,228}, 210},{{235,229}, 2325},{{235,230}, 212},{{235,231}, 4},{{235,232}, 4021},{{235,234}, 499},{{235,235}, 73},{{235,236}, 3},{{235,237}, 160},{{235,238}, 3976},{{235,239}, 66},{{235,241}, 860},{{235,242}, 27},{{235,243}, 747},{{235,244}, 5},{{235,247}, 133},{{235,248}, 1},{{235,249}, 1},{{235,251}, 772},{{235,252}, 2186},{{235,253}, 1},{{235,254}, 515},{{235,255}, 1093},{{235,32}, 5041},{{236,224}, 1745},{{236,225}, 2},{{236,227}, 38},{{236,229}, 1708},{{236,231}, 2},{{236,232}, 2183},{{236,234}, 43},{{236,235}, 48},{{236,236}, 10},{{236,237}, 709},{{236,238}, 2217},{{236,239}, 139},{{236,240}, 27},{{236,241}, 84},{{236,242}, 10},{{236,243}, 1391},{{236,244}, 1},{{236,246}, 22},{{236,247}, 17},{{236,248}, 4},{{236,249}, 1},{{236,251}, 394},{{236,252}, 15},{{236,253}, 1},{{236,254}, 39},{{236,255}, 276},{{236,32}, 4660},{{237,224}, 6499},{{237,225}, 7},{{237,226}, 6},{{237,227}, 105},{{237,228}, 718},{{237,229}, 5502},{{237,230}, 14},{{237,231}, 11},{{237,232}, 4178},{{237,234}, 139},{{237,235}, 1},{{237,236}, 1},{{237,237}, 1821},{{237,238}, 5610},{{237,239}, 6},{{237,240}, 25},{{237,241}, 254},{{237,242}, 378},{{237,243}, 1683},{{237,244}, 6},{{237,246}, 361},{{237,247}, 120},{{237,248}, 22},{{237,249}, 91},{{237,251}, 1935},{{237,252}, 634},{{237,253}, 2},{{237,254}, 95},{{237,255}, 2122},{{237,32}, 2857},{{238,224}, 1},{{238,225}, 1928},{{238,226}, 5092},{{238,227}, 2937},{{238,228}, 2829},{{238,229}, 1330},{{238,230}, 1005},{{238,231}, 552},{{238,232}, 494},{{238,233}, 2282},{{238,234}, 1060},{{238,235}, 4292},{{238,236}, 3073},{{238,237}, 4196},{{238,238}, 103},{{238,239}, 686},{{238,240}, 3912},{{238,241}, 4420},{{238,242}, 4090},{{238,243}, 31},{{238,244}, 280},{{238,245}, 344},{{238,246}, 54},{{238,247}, 833},{{238,248}, 815},{{238,249}, 79},{{238,253}, 14},{{238,254}, 467},{{238,255}, 386},{{238,32}, 13637},{{239,224}, 733},{{239,227}, 9},{{239,229}, 1543},{{239,232}, 475},{{239,234}, 39},{{239,235}, 452},{{239,237}, 33},{{239,238}, 5433},{{239,239}, 51},{{239,240}, 3765},{{239,241}, 2},{{239,242}, 31},{{239,243}, 436},{{239,246}, 1},{{239,247}, 5},{{239,248}, 8},{{239,251}, 125},{{239,252}, 375},{{239,253}, 2},{{239,255}, 227},{{239,32}, 21},{{240,224}, 5294},{{240,225}, 77},{{240,226}, 159},{{240,227}, 175},{{240,228}, 254},{{240,229}, 3776},{{240,230}, 232},{{240,231}, 21},{{240,232}, 3304},{{240,234}, 162},{{240,235}, 38},{{240,236}, 148},{{240,237}, 409},{{240,238}, 4351},{{240,239}, 27},{{240,240}, 27},{{240,241}, 151},{{240,242}, 406},{{240,243}, 1940},{{240,244}, 13},{{240,245}, 84},{{240,246}, 61},{{240,247}, 51},{{240,248}, 143},{{240,249}, 41},{{240,251}, 903},{{240,252}, 512},{{240,253}, 2},{{240,254}, 129},{{240,255}, 673},{{240,32}, 821},{{241,224}, 895},{{241,225}, 27},{{241,226}, 1090},{{241,227}, 5},{{241,228}, 190},{{241,229}, 2123},{{241,230}, 14},{{241,231}, 32},{{241,232}, 1049},{{241,234}, 3267},{{241,235}, 1467},{{241,236}, 619},{{241,237}, 756},{{241,238}, 1556},{{241,239}, 1072},{{241,240}, 165},{{241,241}, 475},{{241,242}, 6618},{{241,243}, 459},{{241,244}, 11},{{241,245}, 116},{{241,246}, 13},{{241,247}, 202},{{241,248}, 32},{{241,250}, 8},{{241,251}, 252},{{241,252}, 2104},{{241,253}, 1},{{241,254}, 82},{{241,255}, 1932},{{241,32}, 1937},{{242,224}, 3415},{{242,225}, 18},{{242,226}, 1340},{{242,227}, 6},{{242,228}, 82},{{242,229}, 2868},{{242,230}, 1},{{242,231}, 4},{{242,232}, 2131},{{242,234}, 217},{{242,235}, 172},{{242,236}, 30},{{242,237}, 557},{{242,238}, 8443},{{242,239}, 38},{{242,240}, 1783},{{242,241}, 512},{{242,242}, 66},{{242,243}, 1116},{{242,244}, 9},{{242,245}, 14},{{242,246}, 76},{{242,247}, 103},{{242,249}, 12},{{242,250}, 25},{{242,251}, 983},{{242,252}, 3094},{{242,253}, 6},{{242,254}, 34},{{242,255}, 309},{{242,32}, 2887},{{243,224}, 12},{{243,225}, 323},{{243,226}, 533},{{243,227}, 782},{{243,228}, 1215},{{243,229}, 90},{{243,230}, 803},{{243,231}, 550},{{243,232}, 11},{{243,233}, 56},{{243,234}, 623},{{243,235}, 953},{{243,236}, 627},{{243,237}, 190},{{243,238}, 8},{{243,239}, 348},{{243,240}, 360},{{243,241}, 885},{{243,242}, 882},{{243,243}, 1},{{243,244}, 4},{{243,245}, 227},{{243,246}, 1},{{243,247}, 439},{{243,248}, 480},{{243,249}, 122},{{243,253}, 14},{{243,254}, 634},{{243,255}, 43},{{243,32}, 4153},{{244,224}, 114},{{244,229}, 87},{{244,232}, 401},{{244,234}, 7},{{244,235}, 58},{{244,236}, 3},{{244,238}, 37},{{244,240}, 305},{{244,241}, 4},{{244,242}, 4},{{244,243}, 45},{{244,244}, 3},{{244,251}, 12},{{244,252}, 1},{{244,253}, 1},{{244,32}, 117},{{245,224}, 619},{{245,226}, 82},{{245,229}, 24},{{245,232}, 98},{{245,235}, 39},{{245,236}, 35},{{245,237}, 95},{{245,238}, 1428},{{245,239}, 1},{{245,240}, 47},{{245,241}, 23},{{245,242}, 12},{{245,243}, 77},{{245,250}, 2},{{245,32}, 1989},{{246,224}, 359},{{246,226}, 12},{{246,227}, 17},{{246,229}, 680},{{246,232}, 143},{{246,234}, 110},{{246,235}, 3},{{246,237}, 16},{{246,238}, 262},{{246,243}, 312},{{246,251}, 74},{{246,32}, 175},{{247,224}, 1351},{{247,229}, 1871},{{247,232}, 742},{{247,234}, 143},{{247,235}, 23},{{247,237}, 291},{{247,238}, 59},{{247,240}, 13},{{247,242}, 2171},{{247,243}, 364},{{247,248}, 44},{{247,252}, 123},{{247,253}, 1},{{247,32}, 101},{{248,224}, 872},{{248,226}, 10},{{248,229}, 1371},{{248,232}, 1218},{{248,234}, 257},{{248,235}, 287},{{248,236}, 12},{{248,237}, 210},{{248,238}, 204},{{248,239}, 34},{{248,240}, 2},{{248,241}, 1},{{248,242}, 101},{{248,243}, 183},{{248,252}, 204},{{248,32}, 70},{{249,224}, 259},{{249,229}, 753},{{249,232}, 412},{{249,237}, 17},{{249,240}, 1},{{249,243}, 42},{{249,252}, 12},{{249,253}, 1},{{249,32}, 7},{{250,229}, 142},{{250,254}, 109},{{250,255}, 32},{{250,32}, 1},{{251,225}, 318},{{251,226}, 683},{{251,227}, 69},{{251,228}, 51},{{251,229}, 570},{{251,230}, 18},{{251,231}, 29},{{251,232}, 8},{{251,233}, 947},{{251,234}, 116},{{251,235}, 1391},{{251,236}, 924},{{251,237}, 219},{{251,238}, 1},{{251,239}, 79},{{251,240}, 222},{{251,241}, 495},{{251,242}, 336},{{251,243}, 3},{{251,245}, 545},{{251,246}, 1},{{251,247}, 82},{{251,248}, 329},{{251,249}, 1},{{251,32}, 2724},{{252,225}, 66},{{252,226}, 3},{{252,227}, 26},{{252,228}, 22},{{252,229}, 588},{{252,231}, 83},{{252,232}, 46},{{252,234}, 695},{{252,236}, 217},{{252,237}, 635},{{252,238}, 27},{{252,241}, 551},{{252,242}, 62},{{252,244}, 4},{{252,246}, 55},{{252,247}, 26},{{252,248}, 257},{{252,249}, 5},{{252,254}, 227},{{252,255}, 241},{{252,32}, 6580},{{253,227}, 6},{{253,228}, 2},{{253,231}, 2},{{253,233}, 7},{{253,234}, 33},{{253,235}, 50},{{253,236}, 6},{{253,237}, 30},{{253,239}, 6},{{253,240}, 32},{{253,241}, 46},{{253,242}, 1372},{{253,245}, 3},{{253,246}, 1},{{253,248}, 1},{{253,32}, 13},{{254,225}, 188},{{254,227}, 1},{{254,228}, 221},{{254,230}, 4},{{254,231}, 17},{{254,234}, 2},{{254,235}, 25},{{254,236}, 16},{{254,237}, 52},{{254,240}, 41},{{254,241}, 89},{{254,242}, 259},{{254,245}, 4},{{254,246}, 29},{{254,247}, 37},{{254,248}, 43},{{254,249}, 276},{{254,254}, 23},{{254,32}, 2134},{{255,225}, 21},{{255,226}, 167},{{255,227}, 190},{{255,228}, 453},{{255,229}, 61},{{255,230}, 322},{{255,231}, 971},{{255,232}, 7},{{255,233}, 12},{{255,234}, 48},{{255,235}, 561},{{255,236}, 208},{{255,237}, 384},{{255,239}, 9},{{255,240}, 25},{{255,241}, 554},{{255,242}, 880},{{255,244}, 1},{{255,245}, 89},{{255,246}, 21},{{255,247}, 76},{{255,248}, 2},{{255,249}, 91},{{255,254}, 56},{{255,255}, 128},{{255,32}, 7035},{{32,224}, 1914},{{32,225}, 4691},{{32,226}, 9542},{{32,227}, 3306},{{32,228}, 4375},{{32,229}, 2430},{{32,230}, 1066},{{32,231}, 2652},{{32,232}, 6805},{{32,233}, 17},{{32,234}, 7033},{{32,235}, 1665},{{32,236}, 3608},{{32,237}, 9388},{{32,238}, 7722},{{32,239}, 9759},{{32,240}, 2792},{{32,241}, 10150},{{32,242}, 4673},{{32,243}, 2419},{{32,244}, 514},{{32,245}, 720},{{32,246}, 194},{{32,247}, 3261},{{32,248}, 635},{{32,249}, 47},{{32,250}, 1},{{32,251}, 2},{{32,252}, 1},{{32,253}, 1559},{{32,254}, 52},{{32,255}, 991}, {{95, 95}, 1}});

#endif //TELEGRAM_ARTICLE_STAT_H
