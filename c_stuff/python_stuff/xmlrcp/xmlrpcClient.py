from xmlrpc import client

class XMLRPCClient():
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.server = client.ServerProxy(f'http://{self.host}:{self.port}')

    def call_function(self, function_name, *args):
        return getattr(self.server, function_name)(*args)

    def _send_request_text(self, request_text):
        return request_text
    
if __name__ == '__main__':
    client = XMLRPCClient('localhost', 8000)
    print(client.call_function('add', 1, 2))