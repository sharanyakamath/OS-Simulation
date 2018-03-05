from django.contrib import admin

# Register your models here.
from .models import Sch_Algo

def Apply_FCFS(modeladmin,request,query):
    Apply_FCFS.short_description = 'Apply FCFS'

def Apply_SJFnon(modeladmin,request,query):
    Apply_SJFnon.short_description = 'Apply SJF Non-Preemptive'

def Apply_SJF(modeladmin,request,query):
    Apply_SJF.short_description = 'Apply SJF Preemptive'    

def Apply_Prioritynon(modeladmin,request,query):
    Apply_Prioritynon.short_description = 'Apply Priority Non-Preemptive'

def Apply_Priority(modeladmin,request,query):
    Apply_Priority.short_description = 'Apply Priority Preemptive'

def Apply_PriorityAging(modeladmin,request,query):
    Apply_PriorityAging.short_description = 'Apply Priority Preemptive Aging'      

def Apply_RoundRobin(modeladmin,request,query):
    Apply_RoundRobin.short_description = 'Apply Round Robin'    

class Sch_AlgoAdmin(admin.ModelAdmin):
    list_display = ['arrival_time','burst_time']
    actions = [Apply_FCFS , Apply_SJFnon ,Apply_SJF,Apply_Prioritynon,Apply_Priority,Apply_PriorityAging, Apply_RoundRobin]

admin.site.register(Sch_Algo,Sch_AlgoAdmin)