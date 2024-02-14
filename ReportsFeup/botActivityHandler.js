// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

const {
    TurnContext,
    MessageFactory,
    TeamsActivityHandler,
    CardFactory,
    ActionTypes,
    TeamsActivityExtensions
} = require('botbuilder');
const { response } = require('express');
var AWS = require('aws-sdk');
var lexruntime = new AWS.LexRuntime();

class BotActivityHandler extends TeamsActivityHandler {    
    
    constructor() {
        super();   
        this.conversationReferences = [];
        this.contexts = [];

        this.onConversationUpdate(async (context, next) => {
            this.addConversationReference(context.activity);
            this.addContext(context);

            await next();
        });

        this.onMessage(async (turnContext, next) => {
            let message = MessageFactory.text("You'll get a notification, if you've turned them on.");
            //var a = new TeamsActivityExtensions();
            //a.TeamsNotifyUser();
        
            await turnContext.sendActivity(message);
            
        
            // By calling next() you ensure that the next BotHandler is run.
            await next();
        });
        /*
        this.onMessage(async (context, next) => {
            this.addConversationReference(context.activity);
            //this.addContext(context);

            // Echo back what the user said
            await context.sendActivity(`You sent '${ context.activity.text }'`);
            TeamsNotifyUser("message");
            //await this.callLex(context);
            //var a = context.activity.conversation.tenantId;
            /*let counter = 0;
            const task = () => {  
                this.checkScraimUpdates();
                counter++;
                const interval = setInterval(() => context.sendActivity("notification message"), 10000);
                setTimeout(() => clearInterval(interval), 100000);
            };
            task();
            await this.messageAllMembersAsync(context);
            await next();
        });*/

        this.onMembersAdded(async (context, next) => {
            
            this.addContext(context);
            const membersAdded = context.activity.membersAdded;
            for (let cnt = 0; cnt < membersAdded.length; cnt++) {
                if (membersAdded[cnt].id !== context.activity.recipient.id) {
                    const welcomeMessage = 'Welcome to the Proactive Bot sample.  Navigate to http://localhost:3978/api/notify to proactively message everyone who has previously messaged this bot.';
                    await context.sendActivity(welcomeMessage);
                }
            }


            
            // By calling next() you ensure that the next BotHandler is run.
            await next();
        });

    }


/*    async callLex(context) {
        //Error [ConfigError]: Missing region in config
        const params = {
            botAlias: 'prod',
            botName: 'botName',
            userId: context.activity.from.id,
            contentType: 'text/plain; charset=utf-8',
            accept: 'text/plain; charset=utf-8',
            inputStream: context.activity.text.trim()
        }
        let request = lexruntime.postContent(params)
        await request.promise().then(
            async response => {
                console.log(response)
                console.log('Success!')
                await context.sendActivity(response.message)          
            },
            err => {
                console.log(err)
                console.log('Error!')
            })
    }*/
     async messageAllMembersAsync(context) {
         //Error : messageAllMembersAsync
        const members = await TeamsInfo.getPagedMembers(context);
    
        members.forEach(async (teamMember) => {
            const message = MessageFactory.text('Hello ${ teamMember.givenName } ${ teamMember.surname }. I\'m a Teams conversation bot.');
    
            var ref = TurnContext.getConversationReference(context.activity);
            ref.user = teamMember;
    
            await context.adapter.createConversation(ref,
                async (t1) => {
                    const ref2 = TurnContext.getConversationReference(t1.activity);
                    await t1.adapter.continueConversation(ref2, async (t2) => {
                        await t2.sendActivity(message);
                       
                    });
                });
        });
        await context.sendActivity(MessageFactory.text('All messages have been sent.'));
    } 

    addConversationReference(activity) {
        const conversationReference = TurnContext.getConversationReference(activity);
        this.conversationReferences[conversationReference.conversation.id] = conversationReference;
    }

    addContext(context) {
        this.contexts.push(context);
    }
    /* Messaging Extension - Action */
    /* Building a messaging extension action command is a two-step process.
        (1) Define how the messaging extension will look and be invoked in the client.
            This can be done from the Configuration tab, or the Manifest Editor.
            Learn more: https://aka.ms/teams-me-design-action.
        (2) Define how the bot service will respond to incoming action commands.
            Learn more: https://aka.ms/teams-me-respond-action.
        
        NOTE:   Ensure the bot endpoint that services incoming messaging extension queries is
                registered with Bot Framework.
                Learn more: https://aka.ms/teams-register-bot.
    */

    // Invoked when the service receives an incoming action command.
    handleTeamsMessagingExtensionSubmitAction(context, action) {
        /* Commands are defined in the manifest file. This can be done using the Configuration tab, editing
           the manifest Json directly, or using the manifest editor in App Studio. This project includes two
           commands to help get you started: createCard and shareMessage.
        */
        switch (action.commandId) {
        case 'login':
            return loginCommand(context, action);
        case 'scheduleMeeting':
            return scheduleMeetingCommand(context, action);
        case 'createCard':
            return createCardCommand(context, action);
        case 'shareMessage':
            return shareMessageCommand(context, action);
        default:
            throw new Error('NotImplemented');
        }
    }

    async checkScraimUpdates() {
        console.log("check updates"); 
        for (var context of this.contexts){
            console.log("context"); 
            try {
                await context.sendActivity(`Notifying `);
            }
            catch (err) {
                console.log(err);
            }
            //await next();
        }
    }


}

function sendRequestToScraim(json, route){
    var XMLHttpRequest = require("xmlhttprequest").XMLHttpRequest;
    var xhr = new XMLHttpRequest();
    var url = "https://lgp2021.scraim.com/" + route;
    xhr.open("POST", url, true);
    xhr.setRequestHeader('Content-Type', 'application/json');
    xhr.send(JSON.stringify(json));
    let data = {};
    xhr.onload = function() {
        console.log(this.responseText);
        try {
            data = JSON.parse(this.responseText);
            console.log(data);
        }
        catch {
            console.log("ERROR in response to login request");
        }
        return data;
    }
}

function loginCommand(context, action) {
    var json = {username: action.data.username, password: action.data.username, format: "json"};
    sendRequestToScraim(json, "users/api/login/");
    action.data.subTitle = "Login request sent";
    action.data.text = action.data.username;
    return createCardCommand(context, action)
}


function scheduleMeetingCommand(context, action) {
    action.data.subTitle = "Meeting:";
    action.data.text = action.data.date;
    return createCardCommand(context, action)
}

function createCardCommand(context, action) {
    const data = action.data;
    const heroCard = CardFactory.heroCard(data.title, data.text);
    heroCard.content.subtitle = data.subTitle;
    const attachment = { contentType: heroCard.contentType, content: heroCard.content, preview: heroCard };

    return {
        composeExtension: {
            type: 'result',
            attachmentLayout: 'list',
            attachments: [
                attachment
            ]
        }
    };
}

function shareMessageCommand(context, action) {
    // The user has chosen to share a message by choosing the 'Share Message' context menu command.
    let userName = 'unknown';
    if (action.messagePayload.from &&
            action.messagePayload.from.user &&
            action.messagePayload.from.user.displayName) {
        userName = action.messagePayload.from.user.displayName;
    }

    // This Messaging Extension example allows the user to check a box to include an image with the
    // shared message.  This demonstrates sending custom parameters along with the message payload.
    let images = [];
    const includeImage = action.data.includeImage;
    if (includeImage === 'true') {
        images = ['https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQtB3AwMUeNoq4gUBGe6Ocj8kyh3bXa9ZbV7u1fVKQoyKFHdkqU'];
    }
    const heroCard = CardFactory.heroCard(`${ userName } originally sent this message:`,
        action.messagePayload.body.content,
        images);

    if (action.messagePayload.attachments && action.messagePayload.attachments.length > 0) {
        // This sample does not add the MessagePayload Attachments.  This is left as an
        // exercise for the user.
        heroCard.content.subtitle = `(${ action.messagePayload.attachments.length } Attachments not included)`;
    }

    const attachment = { contentType: heroCard.contentType, content: heroCard.content, preview: heroCard };

    return {
        composeExtension: {
            type: 'result',
            attachmentLayout: 'list',
            attachments: [
                attachment
            ]
        }
    };
}

module.exports.BotActivityHandler = BotActivityHandler;

