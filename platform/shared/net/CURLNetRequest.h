#ifndef RHO_CURL_NET_REQUEST_041be6266e3e424c8a8e7b8a412f01f0
#define RHO_CURL_NET_REQUEST_041be6266e3e424c8a8e7b8a412f01f0

//#include "curl/lib/setup.h"
#include "curl/curl.h"
#include "net/INetRequest.h"
#include "logging/RhoLog.h"
#include "common/RhoFile.h"

namespace rho
{
namespace net
{

class CURLNetRequest : public INetRequestImpl
{
    DEFINE_LOGCLASS;
    
    class CURLHolder
    {
    public:
        CURLHolder();
        ~CURLHolder();
        
        CURL *curl() {return m_curl;}
        
        curl_slist *set_options(const char *method, const String& strUrl, const String& strBody,
                                IRhoSession* pSession, Hashtable<String,String>* pHeaders);
        CURLcode perform();
        
        void cancel() {deactivate();}
        
        boolean sslVerifyPeer() {return m_sslVerifyPeer;}
        void sslVerifyPeer(boolean mode) {m_sslVerifyPeer = mode;}
        
    private:
        void activate();
        void deactivate();
        
    private:
        CURL *m_curl;
        CURLM *m_curlm;
        char *errbuf[CURL_ERROR_SIZE];
        common::CMutex m_lock;
        int m_active;
        
        boolean m_bTraceCalls;
        long timeout;
        boolean m_sslVerifyPeer;
        
        String mStrMethod;
        String mStrUrl;
        String mStrBody;
    };
    
public:
    virtual INetResponse* doRequest( const char* method, const String& strUrl, const String& strBody, IRhoSession* oSession, Hashtable<String,String>* pHeaders );
    virtual INetResponse* pullFile(const String& strUrl, common::CRhoFile& oFile, IRhoSession* oSession, Hashtable<String,String>* pHeaders);
    virtual INetResponse* pushMultipartData(const String& strUrl, VectorPtr<CMultipartItem*>& arItems, IRhoSession* oSession, Hashtable<String,String>* pHeaders);

    virtual void cancel();

    virtual boolean getSslVerifyPeer() {return m_curl.sslVerifyPeer();}
    virtual void setSslVerifyPeer(boolean mode){m_curl.sslVerifyPeer(mode);}

    virtual INetResponse* createEmptyNetResponse();
private:
    INetResponse* doPull(const char *method, const String &strUrl, const String &strBody, common::CRhoFile *oFile, IRhoSession *oSession, Hashtable<String,String>* pHeaders);
    int getResponseCode(CURLcode err, String const &body, IRhoSession* oSession);
    int getResponseCode(CURLcode err, Vector<char> const &body, IRhoSession* oSession);
    int getResponseCode(CURLcode err, char const *body, size_t bodysize, IRhoSession* oSession);
    String makeCookies();
    INetResponse *makeResponse(String const &body, int nErrorCode);
    INetResponse *makeResponse(Vector<char> const &body, int nErrorCode);
    INetResponse *makeResponse(char const *body, size_t bodysize, int nErrorCode);
	CURLcode doCURLPerform(const String& strUrl);
	
    CURLHolder m_curl;
};

} // namespace net
} // namespace rho

#endif // RHO_CURL_NET_REQUEST_041be6266e3e424c8a8e7b8a412f01f0

