// Fairyprincess  Proxy Auto-Config
//  PAC files described well: https://calomel.org/proxy_auto_config.html

// Define the network paths (direct, proxy and deny)

// Default connection
var direct = "DIRECT";

// UK Proxy Server
//var ukProxy = "PROXY 83.170.113.116:80";
var ukProxy = "PROXY proxy.mysetup.co.uk:80";

// Default localhost for denied connections
var deny = "PROXY 127.0.0.1:65535";

//
// Proxy Logic
//

function FindProxyForURL(url, host)
{

// Use Proxy?
if (dnsDomainIs(host, ".bbc.co.uk")
  || dnsDomainIs(host, ".itv.com")
  || dnsDomainIs(host, ".nba.com")
  || dnsDomainIs(host, ".ip2location.com")
  || dnsDomainIs(host, ".whatismyip.com")
  || dnsDomainIs(host, ".channel4.com")
  )
  { return ukProxy; }
 else
  { return direct; }

// Default DENY
{ return deny; }

}
