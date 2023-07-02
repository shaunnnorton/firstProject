#include <iostream>
#include "src/headers/main.hpp"



using namespace std;
using namespace home;
using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPMessage;
using Poco::StreamCopier;
using Poco::Path;
using Poco::URI;
using Poco::Exception;


bool doRequest(Poco::Net::HTTPClientSession& session, Poco::Net::HTTPRequest& request, Poco::Net::HTTPResponse& response)
{
	session.sendRequest(request);
	istream& rs = session.receiveResponse(response);
	cout << response.getStatus() << " " << response.getReason() << endl;
	if (response.getStatus() != Poco::Net::HTTPResponse::HTTP_UNAUTHORIZED)
	{
		StreamCopier::copyStream(rs, cout);
		return true;
	}
	else
	{
		Poco::NullOutputStream null;
		StreamCopier::copyStream(rs, null);
		return false;
	}
}



int main(int argc, char** argv)
{
    URI uri("http://www.google.com");
    string path(uri.getPathAndQuery());
    if (path.empty()) path = "/";
    HTTPClientSession session(uri.getHost(), uri.getPort());
    HTTPRequest request(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
    HTTPResponse response;

    if (!doRequest(session, request, response))
    {
        cerr << "Invalid username or password" << endl;
        return 1;
    }
}


// int main()
// {
//     calculate calc;
//     int value1 = calc.add(1,2);
//     cout << "Hello, World!" << endl;
//     cout << " Add "<< calc.add(1,2) << endl;
//     cout << " Multiply " << calc.multiply(1,2) << endl;
//     cout << " Kill " << calc.kill(1,2) << endl;
//     return 0;
// }