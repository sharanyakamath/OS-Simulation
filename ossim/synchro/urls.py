from django.conf.urls import url,include
from django.contrib import admin
from . import views

app_name = 'synchro'
urlpatterns =[
    url(r'^semaphores/$', views.semaphores, name='semaphores'),
    url(r'^socket/$', views.socket, name='socket'),
    url(r'^socket/SocketIndex/$', views.SocketIndex, name='SocketIndex'),
    url(r'^socket/Socket/$', views.Socket, name='Socket'),
    url(r'^socket/Bind/$', views.Bind, name='Bind'),
    url(r'^socket/Listen/$', views.Listen, name='Listen'),
    url(r'^socket/Connect/$', views.Connect, name='Connect'),
    url(r'^socket/Accept/$', views.Accept, name='Accept'),
    url(r'^socket/Send/$', views.Send, name='Send'),
    url(r'^socket/Receive/$', views.Receive, name='Receive'),
    url(r'^socket/Close/$', views.Close, name='Close'),
    url(r'^socket/SocketIndex2/$', views.SocketIndex2, name='SocketIndex2'),
    url(r'^socket/Socket2/$', views.Socket2, name='Socket2'),
    url(r'^socket/Bind2/$', views.Bind2, name='Bind2'),
    url(r'^socket/Send2/$', views.Send2, name='Send2'),
    url(r'^socket/Receive2/$', views.Receive2, name='Receive2'),
    url(r'^socket/Close2/$', views.Close2, name='Close2'),
    
    url(r'^deadlocks/$', views.deadlocks, name='deadlocks'),
    url(r'^semaphores/demo/(?P<pk>[0-9]+)/$', views.sem_demo, name='sem_demo'),
    url(r'^socket/demo/(?P<pk>[0-9]+)/$', views.socket_demo, name='socket_demo'),
    url(r'^bankalgo/$', views.bankalgo, name='bankalgo'),
]
