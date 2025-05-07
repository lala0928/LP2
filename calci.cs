// calci.apxc
//sample calulator code
public class calci {

    public Double val1 {get;set;}
    public Double val2 {get;set;}
	public Double result {get;set;}
    public string func {get;set;}
    
    public calci()
    {
        
    }
    
    public void find()
    {
   		if(func == 'add')
        {
            result= val1 +val2 ;
            
        }
        else if (func=='sub')
        {
            result=val1-val2;
        }
        else if (func=='div')
            
        {
            result=val1/val2;
        }
         else
         {
             Integer temp =math.mod(Integer.valueOf(val1),Integer.valueOf(val2));
             result = Double.valueOf(temp);
         }
            
    }
    
}




//calci.vfp
<apex:page controller="calci">
    <apex:form >
        
    <apex:pageBlock >
        <apex:pageBlockSection >
        <apex:pageBlockSectionItem >
            <apex:outputLabel value="value 1"/>
            
            </apex:pageBlockSectionItem>
                <apex:pageBlockSectionItem >
            <apex:inputText value="{!val1}"/>
            
            </apex:pageBlockSectionItem>
            
                    <apex:pageBlockSectionItem >
            <apex:outputLabel value="value 2"/>
            
            </apex:pageBlockSectionItem>
                <apex:pageBlockSectionItem >
            <apex:inputText value="{!val2}"/>
            
            </apex:pageBlockSectionItem>
            
            <apex:pageBlockSectionItem >
            
            <apex:selectRadio value="{!func}" layout="pageDirection">
                <apex:selectOption itemValue="add" itemLabel="Add"/>
                <apex:selectOption itemValue="sub" itemLabel="Subtract"/>
                <apex:selectOption itemValue="div" itemLabel="Division"/>
                <apex:selectOption itemValue="mod" itemLabel="Modulo Division"/>
                
                
                
                </apex:selectRadio>>
            
            </apex:pageBlockSectionItem>
            <apex:pageBlockSectionItem >
   
            </apex:pageBlockSectionItem>
            
                        <apex:pageBlockSectionItem >
                            <apex:outputLabel value="Result"/>
                            
            </apex:pageBlockSectionItem>
            <apex:pageBlockSectionItem >
            <apex:inputText value="{!result}" id="res"  />
                <apex:actionStatus id="sts" startText="Finding.."  />
                
            
            </apex:pageBlockSectionItem>
        </apex:pageBlockSection>
    <apex:pageBlockButtons >
        <apex:commandButton value="Find" action="{!find}" reRender="res" status="sts"/>
        </apex:pageBlockButtons>
        </apex:pageBlock>
        
    </apex:form>
    
</apex:page>