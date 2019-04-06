function getUser() {
        var requ = new XMLHttpRequest()
        requ.open('POST', 'https://api.vk.com/method/friends.get')
        requ.onreadystatechange = function() {
            if(requ.readyState === XMLHttpRequest.DONE) {
                if(requ.status && requ.status === 200) {
//                   console.log("response", requ.responseText)
                   var results = JSON.parse(requ.responseText)
                   friendsList = results.response.items
                } else {
                    console.log('HTTP:', requ.status, requ.responseText)
                }
            }
        }
        requ.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded')
        requ.send('&fields=photo_medium' + '&user_id=' + oauth.userId + '&access_token=' + oauth.accessToken + '&v=5.92')

}

function getMessages() {
        var requ = new XMLHttpRequest()
        requ.open('POST', 'https://api.vk.com/method/messages.getHistory')
        requ.onreadystatechange = function() {
            if(requ.readyState === XMLHttpRequest.DONE) {
                if(requ.status && requ.status === 200) {
                   console.log("response", requ.responseText)
                   var results = JSON.parse(requ.responseText)
                   messageHistory = results.response
                } else {
                    console.log('HTTP:', requ.status, requ.responseText)
                }
            }
        }
        requ.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded')
        requ.send('&user_id=' + user_Id + '&access_token=' + oauth.accessToken + '&v=5.92')

}

