#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>


namespace http {
    const unsigned short HTTP_RESPONSE_STATUS_100_CONTINUE                      = 100;
    const unsigned short HTTP_RESPONSE_STATUS_101_SWITCHING_PROTOCOLS           = 101;
    const unsigned short HTTP_RESPONSE_STATUS_102_PROCESSING                    = 102;
    const unsigned short HTTP_RESPONSE_STATUS_103_EARLY_HINTS                   = 103;
    const unsigned short HTTP_RESPONSE_STATUS_200_OK                            = 200;
    const unsigned short HTTP_RESPONSE_STATUS_201_CREATED                       = 201;
    const unsigned short HTTP_RESPONSE_STATUS_202_ACCEPTED                      = 202;
    const unsigned short HTTP_RESPONSE_STATUS_203_NON_AUTHORITATIVE_INFORMATION = 203;
    const unsigned short HTTP_RESPONSE_STATUS_204_NO_CONTENT                    = 204;
    const unsigned short HTTP_RESPONSE_STATUS_205_RESET_CONTENT                 = 205;
    const unsigned short HTTP_RESPONSE_STATUS_206_PARTIAL_CONTENT               = 206;
    const unsigned short HTTP_RESPONSE_STATUS_207_MULTI_STATUS                  = 207;
    const unsigned short HTTP_RESPONSE_STATUS_208_ALREADY_REPORTED              = 208;
    const unsigned short HTTP_RESPONSE_STATUS_226_IM_USED                       = 226;
    const unsigned short HTTP_RESPONSE_STATUS_300_MULTIPLE_CHOICES              = 300;
    const unsigned short HTTP_RESPONSE_STATUS_301_MOVED_PERMANENTLY             = 301;
    const unsigned short HTTP_RESPONSE_STATUS_302_FOUND                         = 302;
    const unsigned short HTTP_RESPONSE_STATUS_303_SEE_OTHER                     = 303;
    const unsigned short HTTP_RESPONSE_STATUS_304_NOT_MODIFIED                  = 304;
    const unsigned short HTTP_RESPONSE_STATUS_305_USE_PROXY                     = 305;
    const unsigned short HTTP_RESPONSE_STATUS_307_TEMPORARY_REDIRECT            = 307;
    const unsigned short HTTP_RESPONSE_STATUS_307_PERMANENTLY_REDIRECT          = 401;
    const unsigned short HTTP_RESPONSE_STATUS_400_BAD_REQUEST                   = 400;
    const unsigned short HTTP_RESPONSE_STATUS_401_UNAUTHORIZED                  = 401;
    const unsigned short HTTP_RESPONSE_STATUS_402_PAYMENT_REQUIRED              = 402;
    const unsigned short HTTP_RESPONSE_STATUS_403_FORBIDDEN                     = 403;
    const unsigned short HTTP_RESPONSE_STATUS_404_NOT_FOUND                     = 404;
    const unsigned short HTTP_RESPONSE_STATUS_405_METHOD_NOT_ALLOWED            = 405;
    const unsigned short HTTP_RESPONSE_STATUS_406_NOT_ACCEPTABLE                = 406;
    const unsigned short HTTP_RESPONSE_STATUS_407_PROXY_AUTHENTICATION_REQUIRED = 407;
    const unsigned short HTTP_RESPONSE_STATUS_408_REQUEST_TIMEOUT               = 408;
    const unsigned short HTTP_RESPONSE_STATUS_409_CONFLICT                      = 409;
    const unsigned short HTTP_RESPONSE_STATUS_410_GONE                          = 410;
    const unsigned short HTTP_RESPONSE_STATUS_411_LENGTH_REQUIRED               = 411;
    const unsigned short HTTP_RESPONSE_STATUS_412_PRECONDITION_FAILED           = 412;
    const unsigned short HTTP_RESPONSE_STATUS_413_PAYLOAD_TOO_LARGE             = 413;
    const unsigned short HTTP_RESPONSE_STATUS_414_REQUEST_URI_TOO_LONG          = 414;
    const unsigned short HTTP_RESPONSE_STATUS_415_UNSUPPORTED_MEDIA_TYPE        = 415;
    const unsigned short HTTP_RESPONSE_STATUS_416_RANGE_NOT_SATISFIABLE         = 416;
    const unsigned short HTTP_RESPONSE_STATUS_417_EXPECTATION_FAILED            = 417;
    const unsigned short HTTP_RESPONSE_STATUS_418_IM_A_TEAPOT                   = 418;
    const unsigned short HTTP_RESPONSE_STATUS_421_MISDIRECTED_REQUEST           = 421;
    const unsigned short HTTP_RESPONSE_STATUS_422_UNPROCESSABLE_CONTENT         = 422;
    const unsigned short HTTP_RESPONSE_STATUS_423_LOCKED                        = 423;
    const unsigned short HTTP_RESPONSE_STATUS_424_FAILED_DEPENDENCY             = 424;
    const unsigned short HTTP_RESPONSE_STATUS_425_TOO_EARLY                     = 425;
    const unsigned short HTTP_RESPONSE_STATUS_426_UPGRADE_REQUIRED              = 426;
    const unsigned short HTTP_RESPONSE_STATUS_428_PRECONDITION_REQUIRED         = 428;
    const unsigned short HTTP_RESPONSE_STATUS_429_TOO_MANY_REQUESTS             = 429;
    const unsigned short HTTP_RESPONSE_STATUS_431_HEADER_FIELDS_TOO_LARGE       = 431;
    const unsigned short HTTP_RESPONSE_STATUS_500_INTERNAL_SERVER_ERROR         = 500;
    const unsigned short HTTP_RESPONSE_STATUS_501_NOT_IMPLEMENTED               = 501;
    const unsigned short HTTP_RESPONSE_STATUS_502_BAD_GATEWAY                   = 502;
    const unsigned short HTTP_RESPONSE_STATUS_503_SERVICE_UNAVAILABLE           = 503;
    const unsigned short HTTP_RESPONSE_STATUS_504_GATEWAY_TIMEOUT               = 504;
    const unsigned short HTTP_RESPONSE_STATUS_505_HTTP_VERSION_NOT_SUPPORTED    = 505;
    const unsigned short HTTP_RESPONSE_STATUS_506_VARIANT_ALSO_NEGOTIATES       = 506;
    const unsigned short HTTP_RESPONSE_STATUS_507_INSUFFICIENT_STORAGE          = 507;
    const unsigned short HTTP_RESPONSE_STATUS_508_LOOP_DETECTED                 = 508;
    const unsigned short HTTP_RESPONSE_STATUS_510_NOT_EXTENDED                  = 510;
    const unsigned short HTTP_RESPONSE_STATUS_511_NETWORK_AUTHENTICATION_REQUIRED = 511;

    class Request {
        private:
        std::string method;
        std::string path;
        std::string version;

        std::map<std::string, std::string> headers;
        std::map<std::string, std::string> data;
        public:
        Request() {}
        static Request create_request_from_string(std::string request_str);

        std::string get_method();
        std::string get_path();
        std::string get_version();
        void print_request();
    };
}
