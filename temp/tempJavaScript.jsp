<html>

    <head>
      <title>会员注册</title>
    </head>
    
    
    <body>
        <!-- function check() {
            var name = document.getElement.ById("name").value;
            return ture;
        } -->
        <center>
    
            <form action="#" name="form" method="POST">
                <table border="1">
                    <font face="方正喵呜体" size="5">新会员注册</font>
                    <tr>
                        <td>
                            用户名:
                        </td>
                        <td>
                            <input name="userName" pattern=".{3,10}" title="用户名限制3至10个字符" >
                        </td>
                    </tr>
                    <tr>
                        <td>
                            密码:
                        </td>
                        <td>
                            <input name="password" pattern=".{3,10}" title="密码限制3至10个字符" type="password">
                        </td>
                    </tr>
                    <tr>
                        <td>
                            重复密码:
                        </td>
                        <td>
                            <input type="password">
                        </td>
                    </tr>
                    <tr>
                        <td>
                            用户邮箱:
                        </td>
                        <td>
                            <input type="userMail">
                        </td>
                    </tr>
                    <tr>
                        <td>
                            性别:
                        </td>
                        <td>
                            男<input type="radio" name="sex">
                            女<input type="radio" name="sex">
                        </td>
                    </tr>
                    <tr>
                        <td>
                            兴趣爱好:
                        </td>
                        <td>
                            写代码<input type="checkbox" name="hobby" value="写代码">
                            听音乐<input type="checkbox" name="hobby" value="听音乐">
                            玩游戏<input type="checkbox" name="hobby" value="玩游戏">
                        </td>
                    </tr>
                    <tr>
                        <td>
                            个人介绍:
                        </td>
                        <td>
                            <textarea rows="5" cols="22">
                            </textarea>
                        </td>
                    </tr>
                    <tr>
                        <td>
                            头像:
                        </td>
                        <td>
                            <input type="file" name="photo">
                        </td>
                    </tr>
                </table>
                <input type="submit" value="提交">
            </form>
        </center>
    </body>
    
    </html>